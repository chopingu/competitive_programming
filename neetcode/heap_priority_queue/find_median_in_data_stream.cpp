class MedianFinder {
public:
    multiset<int> s1, s2;

    MedianFinder() {}
    
    void addNum(int num) {
        int tot = s1.size() + s2.size() + 1;
        int le = (tot + 1) / 2;
        if(s1.empty() || num <= *s1.rbegin()) {
            s1.insert(num);
            if(s1.size() > le) {
                auto it = s1.rbegin();
                s2.insert(*it);
                s1.erase(s1.find(*it));
            }

            return;
        }
        s2.insert(num);
        if(s2.size() > tot - le) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(s2.find(*it));
        }
    }
    
    double findMedian() {
        int tot = s1.size() + s2.size();
        if(tot % 2) 
            return *s1.rbegin();

        return (*s1.rbegin() + *s2.begin()) / 2.0;
    }
};
