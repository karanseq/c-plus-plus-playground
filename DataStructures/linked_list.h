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

// forward declaration
template<typename T>
class LinkedList;

template<typename T>
class LinkIterator
{
public:
    explicit LinkIterator(std::nullptr_t) : node_(nullptr)
    {}

    LinkIterator() : node_(nullptr)
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
        return *this;
    }

    inline LinkIterator& operator=(LinkNode<T>* i_node)
    {
        node_ = i_node;
        return *this;
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

    friend class LinkedList<T>;

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

    void PushFront(const T& i_data)
    {
        LinkNode<T> *node = Node(i_data);
        node->next = head_;

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

    void PushBack(const T& i_data)
    {
        LinkNode<T> *node = Node(i_data);
        node->prev = tail_;

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

    inline void Insert(LinkIterator<T>& i_iterator, const T& i_data)
    {
        assert(i_iterator);
        Insert(i_iterator.node_, i_data);
    }

    inline void Erase(LinkIterator<T>& i_iterator)
    {
        assert(i_iterator);
        Erase(i_iterator.node_);
        i_iterator = nullptr;
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
    inline LinkNode<T>* Node(const T& i_data)
    {
        LinkNode<T>* node = new LinkNode<T>;
        assert(node);

        node->prev = nullptr;
        node->next = nullptr;
        node->data = i_data;
        
        ++size_;
        
        return node;
    }

    void Insert(LinkNode<T>* i_node, const T& i_data)
    {
        assert(i_node);

        if (i_node == head_)
        {
            PushFront(i_data);
            return;
        }

        LinkNode<T>* node = Node(i_data);
        node->next = i_node;
        node->prev = i_node->prev;

        if (i_node->prev)
        {
            i_node->prev->next = node;
        }
        i_node->prev = node;
    }

    void Erase(LinkNode<T>* i_node)
    {
        assert(i_node);

        if (i_node == head_)
        {
            head_ = i_node->next;
        }

        if (i_node == tail_)
        {
            tail_ = i_node->prev;
        }

        if (i_node->prev)
        {
            i_node->prev->next = i_node->next;
        }

        if (i_node->next)
        {
            i_node->next->prev = i_node->prev;
        }

        delete i_node;
        --size_;
    }

private:
    LinkNode<T>*            head_;
    LinkNode<T>*            tail_;
    size_t                  size_;

}; // class LinkedList

#endif // LINKED_LIST_H_