#include <bits/stdc++.h>
#define Num HighAccuracyNumber
using namespace std;

// High Accuracy Algorith
// Num a   Num b   long long c
// a.init(c);
// a.add(b); a.minus(b);
// a.multiply(c); a.divide(c);
// a.check();
// a + b    a - b
// a + c    a - c
// a * c    a / c
// a > b    a < b
// a >= b   a <= b
// a == b   a != b


struct HighAccuracyNumber{
	long long num[10005];
	int len;
	void init(long long __N)
	{
		len = 0;
		while (__N)
		{
			num[++len] = __N % 10;
			__N /= 10;
		}
	}
	void add(Num __A)
	{
		int __l = max(len, __A.len);
		long long __ys = 0;
		for (int __i = 1; __i <= __l; __i++)
		{
			num[__i] += __A.num[__i] + __ys;
			__ys = num[__i] / 10;
			num[__i] %= 10;
		}
	}
	void minus(Num __A)
	{
		int __l = max(len, __A.len);
		long long __tw = 0;
		for (int __i = 1; __i <= __l; __i++)
		{
			num[__i] -= __A.num[__i] + __tw;
			while (num[__i] < 0)
			{
				num[__i] += 10;
				__tw++;
			}
		}
	}
	void multiply(long long __x)
	{
		long long __ys = 0;
		for (int __i = 1; __i <= len; __i++)
		{
			num[__i] = num[__i] * __x + __ys;
			__ys = num[__i] / 10;
			num[__i] %= 10;
		}
		while (__ys)
		{
			num[++len] = __ys % 10;
			__ys /= 10;
		}
	}
	void divide(long long __x)
	{
		long long __ys = 0;
		int __i = len;
		while (__i >= 1)
		{
			long long __y = __ys;
			__ys = (num[__i] + __ys) % __x * 10;
			num[__i] = (num[__i] + __y) / __x;
			__i--;
		}
		while (!num[len])
		{
			len--;
		}
	}
	void check()
	{
		long long __ys = 0;
		for (int __i = 1; __i <= len; __i++)
		{
			num[__i] += __ys;
			if (num[__i] >= 10)
			{
				__ys = num[__i] / 10;
				num[__i] %= 10;
			}
		}
		while (__ys)
		{
			num[++len] = __ys % 10;
			__ys /= 10;
		}
		while (!num[len])
			len--;
	}
	friend Num operator +(Num __A, Num __B)
	{
		int __l = max(__A.len, __B.len);
		int __ys = 0;
		for (int __i = 1; __i <= __l; __i++)
		{
			__A.num[__i] += __B.num[__i] + __ys;
			__ys = __A.num[__i] / 10;
			__A.num[__i] %= 10;
		}
		return __A;
	}
	friend Num operator -(Num __A, Num __B)
	{
		int __l = max(__A.len, __B.len);
		long long __tw = 0;
		for (int __i = 1; __i <= __l; __i++)
		{
			__A.num[__i] -= __B.num[__i] + __tw;
			while (__A.num[__i] < 0)
			{
				__A.num[__i] += 10;
				__tw++;
			}
		}
		return __A;
	}
	friend Num operator +(Num __A, long long __B)
	{
		int __i = 1;
		while (__B)
		{
			__A.num[__i++] = __B % 10;
			__B /= 10;
		}
		return __A;
	}
	friend Num operator -(Num __A, long long __B)
	{
		int __i = 1;
		long long __tw = 0;
		while (__B || __tw)
		{
			__A.num[__i] -= __B + __tw;
			__tw = 0;
			while (__A.num[__i] < 0)
			{
				__A.num[__i] += 10;
				__tw++;
			}
			__B /= 10;
		}
		return __A;
	}
	friend Num operator *(Num __A, long long __B)
	{
		long long __ys = 0;
		for (int __i = 1; __i <= __A.len; __i++)
		{
			__A.num[__i] = __A.num[__i] * __B + __ys;
			__ys = __A.num[__i] / 10;
			__A.num[__i] %= 10;
		}
		while (__ys)
		{
			__A.num[++__A.len] = __ys % 10;
			__ys /= 10;
		}
		return __A;
	}
	friend Num operator /(Num __A, long long __B)
	{
		long long __ys = 0;
		int __i = __A.len;
		while (__i >= 1)
		{
			long long __y = __ys;
			__ys = (__A.num[__i] + __ys) % __B * 10;
			__A.num[__i] = (__A.num[__i] + __y) / __B;
			__i--;
		}
		while (!__A.num[__A.len])
		{
			__A.len--;
		}
		return __A;
	}
	friend bool operator <(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] < __B.num[__i])
				return true;
			if (__A.num[__i] > __B.num[__i])
				return false;
		}
		return false;
	}
	friend bool operator >(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] < __B.num[__i])
				return false;
			if (__A.num[__i] > __B.num[__i])
				return true;
		}
		return false;
	}
	friend bool operator <=(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] < __B.num[__i])
				return true;
			if (__A.num[__i] > __B.num[__i])
				return false;
		}
		return true;
	}
	friend bool operator >=(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] < __B.num[__i])
				return false;
			if (__A.num[__i] > __B.num[__i])
				return true;
		}
		return true;
	}
	friend bool operator ==(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] != __B.num[__i])
				return false;
		}
		return true;
	}
	friend bool operator !=(Num __A, Num __B)
	{
		int l1 = __A.len, l2 = __B.len;
		if (l1 != l2)
			return l1 < l2;
		for (int __i = l1; __i >= 1; __i--)
		{
			if (__A.num[__i] != __B.num[__i])
				return true;
		}
		return false;
	}
};
