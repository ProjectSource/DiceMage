#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton
{
private:
	Singleton(Singleton const &);
	Singleton& operator = (Singleton const *);

	static std::auto_ptr<T> instance_;

protected:
	Singleton() {}
	virtual ~Singleton() {}

public:
	static T* instance() {
		if (!instance_.get()) {
			instance_ = std::auto_ptr<T>(new T);
		}
		return instance_.get();
	}
};

template <typename T> std::auto_ptr<T> Singleton<T>::instance_;
#endif
