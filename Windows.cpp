#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAX_X 3480
#define MAX_Y 2160

struct Window
{
	int x;
	int y;
	int w;
	int h;
	int ID;
};

struct Point
{
	int x;
	int y;
};

bool pointInWindow(Window *w, Point * p) {
	int x_left = w->x;
	int x_right = w->x + w->w;
	int y_top = w->y;
	int y_bottom = w->y + w->h;
	if (p->x >= x_left && p->x <= x_right && p->y >= y_top && p->y <= y_bottom) {
		return true;
	}
	return false;
}

int findWindowID(vector<struct Window> & win, Point *p) {
	for (int i = win.size() - 1; i >= 0; i--) {
		if (pointInWindow(&win[i], p)) {
			return win[i].ID;
		}
	}
	return -1;
}

int main() {
	int N, M;
	struct Point * p;
	std::cin >> N >> M;
	if (N <= 0 || N >= 1000 || M <= 0 || M >= 1000)
		return 0;

	p = (struct Point*)malloc(sizeof(struct Point) *M);
	vector<struct Window> win;
	for (int i = 0; i < N; i++) {
		struct Window w;
		scanf("%d", &w.x);
		scanf("%d", &w.y);
		scanf("%d", &w.w);
		scanf("%d", &w.h);
		if (w.x < 0 || w.x >= MAX_X || w.y < 0 || w.y >= MAX_Y)
			return 0;
		if (w.w <= 0 || w.w > MAX_X || w.h <= 0 || w.h > MAX_Y)
			return 0;
		w.ID = i + 1;
		win.push_back(w);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &p[i].x);
		scanf("%d", &p[i].y);
		if (p[i].x < 0 || p[i].x >= MAX_X || p[i].y < 0 || p[i].y >= MAX_Y)
			return 0;
	}

	int last_ID = N;
	for (int i = 0; i < M; i++) {
		int find_window_idx = findWindowID(win, &p[i]);
		if (last_ID != find_window_idx && find_window_idx > 0) {
			Window tmp = win[find_window_idx - 1];
			//vector<Window>::iterator iter = win.begin() + find_window_idx - 1;
			win.erase(win.begin() + find_window_idx - 1);
			win.insert(win.end(), tmp);
			last_ID = find_window_idx;
		}
		cout << find_window_idx << endl;
	}

	cin.get();
	cin.get();
	return 0;
}