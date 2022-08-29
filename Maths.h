#include <bits/stdc++.h>
using namespace std;

bool is_prime(long a)
{
	bool f = true;
	for (int i = 2; i <= a - 1; i++)
		if (a % i == 0)
			f = false;
	return f;
}
bool is_mutual_quality(long a, long b)
{
	if (b == 0)
		return false;
	if (b == 1)
		return true;
	is_mutual_quality(b, a % b);		
}
int _lcm(long a, long b)
{
	long long i;
	for (i = a; i % b != 0;)
		i += a;
	return i;
}
int _gcd(long a, long b)
{
	long long i, x;
	for (i = 1; i <= a; i++)
		if (a % i == 0 && b % i == 0)
			x = i;
	return x;
}
long long factorial(int x)
{
	long long s = 1;
	for (int i = 1; i <= x; i++)
		s *= i;
	return s;
}
int decimalism_to_binary(int x, int y[16])
{
	int a[16], i, z;
	z = x;
	long long s = 0;
	for (i = 0; i <= 15; i++)
		a[i] = 0;
	for (int i = 0; z > 0; i++)
	{
		a[i] = z % 2;
		z /= 2;
	}
	for (int j = 15; j >= 0; j--)
	{
		y[15 - j] = a[j];
	}
	return 0;
}
int binary_to_decimalism(int a[16])
{
	long ans;
	for (int i = 0; i <= 15; i++)
	{
		ans *= 2;
		ans += a[i];
	}
	return ans;
}

long reverse(long x, int a)
{
	long y = 0, z = x;
	for (int i = 1; i <= a; i++)
	{
		y *= 10;
		y += z % 10;
		z /= 10;
	}
	return y;
}

bool is_lunar_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

int month_day_number(int year, int month)
{
	switch (month)
	{
		case 4:
			return 30;
			break;
		case 6:
			return 30;
			break;
		case 9:
			return 30;
			break;
		case 11:
			return 30;
			break;
		case 2:
			if (is_lunar_year(year))
				return 29;
			else
				return 28;
			break;
		default:
			return 31;
	}
}


/*



dfs:
-------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int x;
_____;
void finish()
{
	_______;
}
void dfs(int n)
{
	if (n > x)
	{
		finish();
		return;
	}
	else
	{
		_______________;
		for (int i = ___; i <= ____; i++)
			if (_____)
			{
				_______;
				dfs(n + 1);
				_______;
			}
	}
}
int main()
{
	________;
	cin >> n;
	dfs(1);
	return 0;
}
-------------------------------------------------





bfs:
-------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
struct node{
	int num, step;
};
queue < node > q;
_______;
void input()
{
	_________;
	_________;
}
void finish()
{
	_________;
	_________;
}
bool check(int a)
{
	_________;
	_________;
}
int main()
{
	input();
	q.push({_____, _____});
	________;
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (_____)
		{
			finish();
			return 0;
		}
		for (int i = ___; i <= ____; i++)
		{
			node next;
			next.num = _______;
			if (check(___))
			{
				next.step + 1;
				q.push(next);
			}
		}
	}
	return 0;
}
-------------------------------------------------





Binary Search:
-------------------------------------------------
int BinarySearch(________, int target)
{
    int left = 0, right = ____.size();
    while (left < right)
	{
        int mid = left + (right - left) / 2;
        if (____[mid] == target) return mid;
        else if (____[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}
-------------------------------------------------





Prime sieve:
-------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
const int N = ______;
int a[N + 5];
int main()
{
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!a[i])
		{
			for (int j = i + i; j <= N; j += i)
			{
				a[i] = 1;
			}
		}
	}
	int x;
	if (!a[x])
	{
		__"Yes"__;
	}
	else
	{
		__"No"___;
	}
	return 0;
}
-------------------------------------------------


*/
