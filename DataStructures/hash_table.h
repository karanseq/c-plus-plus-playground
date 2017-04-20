#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <assert.h>
#include <stdint.h>

#include "linked_list.h"

uint32_t GetHash(const char* i_key)
{
    assert(i_key);

    uint32_t hash = 0;
    uint32_t i = 0;
    while ((i_key + i) != nullptr && *(i_key + i) != '\0')
    {
        hash = (hash * 256 + int(*(i_key + i)));
        ++i;
    }
    return hash;
}

template<typename T>
struct HashItem
{
    uint32_t                                hash;
    T                                       value;
};

template<typename T>
class HashTable
{
public:
    HashTable(size_t i_buckets) : buckets_(nullptr),
        num_buckets_(i_buckets),
        num_elements_(0)
    {
        buckets_ = new LinkedList<HashItem<T>>[i_buckets];
    }

    ~HashTable()
    {
        delete[] buckets_;
        buckets_ = nullptr;
    }

    void Insert(const char* i_key, T i_value)
    {
        assert(i_key);

        HashItem<T> item;
        item.hash = GetHash(i_key);
        item.value = i_value;

        const size_t bucket_index = item.hash % num_buckets_;
        buckets_[bucket_index].PushFront(item);

        ++num_elements_;
    }

    void Remove(const char* i_key, T i_value)
    {
        assert(i_key);

        const uint32_t hash = GetHash(i_key);
        const size_t bucket_index = hash % num_buckets_;

        LinkIterator<HashItem<T>> it = buckets_[bucket_index].Front();
        while (it)
        {
            HashItem<T> item = *it;
            if (item.hash == hash && item.value == i_value)
            {
                buckets_[bucket_index].Remove(it);
                --num_elements_;
                return;
            }

            ++it;
        }
    }

    bool Find(const char* i_key, T& o_value) const
    {
        assert(i_key);

        const uint32_t hash = GetHash(i_key);
        const size_t bucket_index = hash % num_buckets_;

        LinkIterator<HashItem<T>> it = buckets_[bucket_index].Front();
        while (it)
        {
            HashItem<T> item = *it;
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
    LinkedList<HashItem<T>>*                buckets_;
    size_t                                  num_buckets_;
    size_t                                  num_elements_;

}; // class HashTable

#endif // HASH_TABLE_H_
