class ContainsPrivateCopyCtor
{
public:
    ContainsPrivateCopyCtor();
    ~ContainsPrivateCopyCtor();

    inline int GetData1() const { return data_1_; }
    inline int GetData2() const { return data_2_; }

private:
    ContainsPrivateCopyCtor(const ContainsPrivateCopyCtor&);
    void operator= (const ContainsPrivateCopyCtor&);

protected:
    int data_1_, data_2_;

    friend class FriendOfThePrivateCopyClass;
};
