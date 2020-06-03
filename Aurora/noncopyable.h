//
// Created by abcdlsj on 2020/6/4.
//

#ifndef AURORA_NONCOPYABLE_H
#define AURORA_NONCOPYABLE_H
namespace Aurora {
    class noncopyable {
    public:
        noncopyable(const noncopyable&) = delete;
        void operator=(const noncopyable&) = delete;

    protected:
        noncopyable() = default;
        ~noncopyable() = default;
    };
}
#endif //AURORA_NONCOPYABLE_H
