#ifndef TMUDUO_NONCOPYABLE_H
#define TMUDUO_NONCOPYABLE_H

namespace muduo
{

class noncopyable
{
 protected:
  noncopyable() = default;
  ~noncopyable() = default;

 private:
  noncopyable(const noncopyable&) = delete;
  void operator=(const noncopyable&) = delete;
};

}

#endif  // TMUDUO_NONCOPYABLE_H
