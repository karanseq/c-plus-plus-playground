#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <assert.h>

template<typename T>
struct LinkNode
{
    LinkNode*               prev;
    LinkNode*               next;
    T                       data;
};

template<typename T>
class LinkIterator
{
public:
    explicit LinkIterator(std::nullptr_t) : node_(nullptr)
    {}

    LinkIterator(LinkNode<T>* i_node) : node_(i_node)
    {}

    ~LinkIterator()
    {}

    LinkIterator(const LinkIterator& i_copy) : node_(i_copy.node_)
    {}

    inline LinkIterator& operator=(const LinkIterator& i_other)
    {
        node_ = i_other.node_;
    }

    inline LinkIterator& operator=(LinkNode<T>* i_node)
    {
        node_ = i_node;
    }

    inline operator bool() const
    {
        return node_ != nullptr;
    }

    inline bool IsValid() const
    {
        return node_ != nullptr;
    }

    inline void operator++()
    {
        assert(node_);
        node_ = node_->next;
    }

    inline void operator++(int)
    {
        assert(node_);
        node_ = node_->next;
    }

    inline void operator--()
    {
        assert(node_);
        node_ = node_->prev;
    }

    inline void operator--(int)
    {
        assert(node_);
        node_ = node_->prev;
    }

    inline bool operator==(const LinkIterator& i_other) const
    {
        return node_ == i_other.node_;
    }

    inline bool operator!=(const LinkIterator& i_other) const
    {
        return node_ != i_other.node_;
    }

    inline T& operator*() const
    {
        assert(node_);
        return node_->data;
    }

private:
    LinkNode<T>*            node_;

}; // class LinkIterator

template<typename T>
class LinkedList
{
public:
    LinkedList() : head_(nullptr),
        tail_(nullptr),
        size_(0)
    {}

    ~LinkedList()
    {
        while (head_)
        {
            PopFront();
        }
    }

    // TODO: Add copy & move constructors and assignment operators
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void PushFront(T i_data)
    {
        LinkNode<T> *node = new LinkNode<T>;
        assert(node);

        node->data = i_data;
        node->next = head_;
        node->prev = nullptr;
        ++size_;

        if (head_)
        {
            head_->prev = node;
        }

        head_ = node;

        if (tail_ == nullptr)
        {
            tail_ = head_;
        }
    }

    void PopFront()
    {
        assert(head_);

        LinkNode<T>* node = head_;

        head_ = head_->next;

        if (head_)
        {
            head_->prev = nullptr;
        }
        else
        {
            tail_ = nullptr;
        }

        delete node;
        --size_;
    }

    void PushBack(T i_data)
    {
        LinkNode<T> *node = new LinkNode<T>;
        assert(node);

        node->data = i_data;
        node->next = nullptr;
        node->prev = tail_;
        ++size_;

        if (tail_)
        {
            tail_->next = node;
        }

        tail_ = node;

        if (head_ == nullptr)
        {
            head_ = tail_;
        }
    }

    void PopBack()
    {
        assert(tail_);

        LinkNode<T>* node = tail_;

        tail_ = tail_->prev;

        if (tail_)
        {
            tail_->next = nullptr;
        }
        else
        {
            head_ = nullptr;
        }

        delete node;
        --size_;
    }

    inline LinkIterator<T> Begin() const
    {
        return LinkIterator<T>(head_);
    }

    inline LinkIterator<T> End() const
    {
        return LinkIterator<T>(nullptr);
    }

    inline LinkIterator<T> Front() const
    {
        return LinkIterator<T>(head_);
    }

    inline LinkIterator<T> Back() const
    {
        return LinkIterator<T>(tail_);
    }

    inline size_t GetSize() const { return size_; }

private:
    LinkNode<T>*            head_;
    LinkNode<T>*            tail_;
    size_t                  size_;

}; // class LinkedList

#endif // LINKED_LIST_H_