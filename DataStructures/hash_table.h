#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <assert.h>
#include <stdint.h>

#include "linked_list.h"

template<typename T>
struct HashItem
{
    uint32_t                                hash;
    T                                       value;
};

template<typename T>
struct HashFunc
{
    HashFunc(uint32_t(*Func)(T)) : GetHash(Func)
    {}

    uint32_t (*GetHash)(T);
};

template<typename Key, typename Value>
class HashTable
{
public:
    HashTable(size_t i_buckets, HashFunc<Key> i_hash_function) : buckets_(nullptr),
        hash_function_(i_hash_function),
        num_buckets_(i_buckets),
        num_elements_(0)
    {
        buckets_ = new LinkedList<HashItem<Value>>[i_buckets];
    }

    ~HashTable()
    {
        delete[] buckets_;
        buckets_ = nullptr;
    }

    // TODO: Add copy & move constructors and assignment operators
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    void Insert(Key i_key, Value i_value)
    {
        assert(i_key);

        HashItem<Value> item;
        item.hash = hash_function_.GetHash(i_key);
        item.value = i_value;

        const size_t bucket_index = item.hash % num_buckets_;
        buckets_[bucket_index].PushFront(item);

        ++num_elements_;
    }

    void Remove(Key i_key, Value i_value)
    {
        assert(i_key);

        const uint32_t hash = hash_function_.GetHash(i_key);
        const size_t bucket_index = hash % num_buckets_;

        LinkIterator<HashItem<Value>> it = buckets_[bucket_index].Front();
        while (it)
        {
            HashItem<Value> item = *it;
            if (item.hash == hash && item.value == i_value)
            {
                buckets_[bucket_index].Remove(it);
                --num_elements_;
                return;
            }

            ++it;
        }
    }

    bool Find(Key i_key, Value& o_value) const
    {
        assert(i_key);

        const uint32_t hash = hash_function_.GetHash(i_key);
        const size_t bucket_index = hash % num_buckets_;

        LinkIterator<HashItem<Value>> it = buckets_[bucket_index].Front();
        while (it)
        {
            HashItem<Value> item = *it;
            if (item.hash == hash)
            {
                o_value = item.value;
                return true;
            }

            ++it;
        }

        return false;
    }

    inline size_t GetBucketCount() const { return num_buckets_; }
    inline size_t GetElementCount() const { return num_elements_; }

private:
    LinkedList<HashItem<Value>>*            buckets_;
    HashFunc<Key>                           hash_function_;
    size_t                                  num_buckets_;
    size_t                                  num_elements_;

}; // class HashTable

#endif // HASH_TABLE_H_