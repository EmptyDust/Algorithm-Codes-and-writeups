
struct BIT
{
#define lowbit(x) x&-x
    std::vector<int> bit;
    int n;
    BIT(int n) {
        bit.resize(n + 1);
        this->n = n;
    }
    void update(int pos, int num = 1) {
        for (int i = pos;i <= n;i += lowbit(i))
            bit[i] += num;
    }
    int query(int pos) {
        int ret = 0;
        for (int i = pos;i;i -= lowbit(i))
            ret += bit[i];
        return ret;
    }
#undef lowbit(x)
};