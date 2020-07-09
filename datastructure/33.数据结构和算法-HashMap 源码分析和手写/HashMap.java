package com.east.datastructure33hashmap;

import java.util.Map;

/**
 *  手写 HashMap 一些关键性的代码
 */
public class HashMap<K,V> {
    // 需求例子 ：跳转到直播页，首先跳转到登录页，登录成功之后再跳转到直播页
    //（明天）比较好的解决方案，随着业务逻辑越来越复杂的情况下，不需要去刻意的去修改原来的代码
    // apt aspectj 做过哪些优化 ap

    class MapEntry<K,V>{
        K key;
        V value;
        MapEntry<K,V> next;
        int hash; // Key 的 hash 值

        public MapEntry(int hash,K key, V value,MapEntry<K, V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }
    }

    /**
     *  散列 table （桶）
     */
    transient MapEntry[] table;

    /**
     *  总共多少的键值对
     */
    int size;


    /**
     *  初始大小为 16
     */
    final int DEFAULT_INITIAL_CAPACITY =  1 << 4;

    /**
     *  扩容阈值（满足这个条件时扩容）
     */
    int threshold;

    /**
     *  扩容因子，如何扩容
     */
    final float loadFactory = 0.75f;

    public V put(K key,V value){
        if(table == null){
            table = new MapEntry[DEFAULT_INITIAL_CAPACITY];
            threshold = (int) (DEFAULT_INITIAL_CAPACITY * loadFactory);
        }

        // 是不是空
        if(key == null){
            // 自行看 hashMap 的源码
            return null;
        }

        // 1. 找到 table 的位置
        int hash = hash(key);
        int index = getIndex(hash,table.length);

        // 2. 判断有没有存在该key
        for (MapEntry<K,V> e = table[index]; e!=null; e = e.next){
            K k;
            if(e.hash == hash && ((k = e.key) == key || (key!=null && key.equals(k)))){
                V oldValue = e.value;
                e.value = value;
                return oldValue;
            }
        }
        // 3. 添加一个新的 MapEntry
        addEntry(hash,key,value,index);
        return null;

    }

    /**
     * 添加一个新的 Entry
     * @param hash
     * @param key
     * @param value
     * @param index
     */
    private void addEntry(int hash, K key, V value, int index) {
        // hash_shift 16 value() >> 16
        // 判断要不要扩容 jni 源码记住 mask_bits(value() >> hash_shift,hash_mask)
        // 1. hash 值相等两个对象不一定相等，（两个对象不相等，hash值可能相等）
        // 2. hash 值不相等的两个对象肯定不相等
        if(size >= threshold && table[index] != null){
            resize(table.length << 1);
            // 重新计算 index
            index = getIndex(hash,table.length);
        }
        // 添加
        createEntry(hash,key,value,index);

        size++;
    }

    private void resize(int newCapacity) {
        MapEntry<K,V>[] newTable = new MapEntry[newCapacity];
        // 直接把之前的数组搬过来，不行！！ 扩容之后 Index 会变 复杂度 O(n)
        transform(newTable);
        table = newTable;
        threshold = (int)(newCapacity * loadFactory);
    }

    /**
     * 重新计算 挪动，散列
     * @param newTable
     */
    private void transform(MapEntry<K, V>[] newTable) {
        int newCapacity = newTable.length;

        for (MapEntry<K, V> entry : table) {
            while (entry!=null){
                // 从原来的数组中获取数据 Entry , 保证新的数组能链上
                MapEntry<K,V> next = entry.next;

                // 重新计算 index
                int index = getIndex(entry.hash,newCapacity);
                // 保证新的数组能链上
                entry.next = newTable[index];
                newTable[index] = entry;

                entry = next;
            }
        }
    }

    private void createEntry(int hash, K key, V value, int index) {
        MapEntry<K,V> newEntry = new MapEntry<>(hash,key,value,table[index]);
        table[index] = newEntry;
    }


    private int hash(K key){
        int h;
        return (key == null) ? 0 : (h=key.hashCode()) ^ (h >>> 16);
    }

    private int getIndex(int hash,int length){
        return hash & length -1; // - 运算符比 & 优先级高
    }

    public V get(K key){
        if(key == null){
            return null;
        }

        MapEntry<K,V> entry = getEntry(key);
        return entry == null ? null : entry.value;
    }

    private MapEntry<K, V> getEntry(K key) {
        // 1. 找到 table 的位置
        int hash = hash(key);
        int index = getIndex(hash, table.length);

        // 2. 判断有没有存在该 key
        for(MapEntry<K,V> e = table[index]; e!=null; e = e.next){
            K k;
            if(hash == e.hash && ((k = e.key) == key || (key != null && key.equals(k)))){
                return e;
            }
        }
        return null;
    }

    public int size(){
        return size;
    }

}
