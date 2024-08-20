 // Siv3D v0.6.14

#include "stdafx.h"

const int FIELD_WIDTH = 15;
const int FIELD_HEIGHT = 30;
const int MINO_WIDTH = 5; 
const int MINO_HEIGHT = 5;

const int FIELD_LINE_WIDTH = 650;
const int FIELD_LINE_HEIGHT = 560;
const int FIELD_WIDTH_0 = 380;
const int FIELD_HEIGHT_0 = 20;



enum minotype {
	TYPE_I, TYPE_L, TYPE_J, TYPE_Z, TYPE_S,
	TYPE_O, TYPE_T, TYPE_MAX
};

enum minoangle {
	ANGLE_0, ANGLE, _90, ANGLE_180, ANGLE_270, ANGLE_MAX
};

Color mino[TYPE_MAX][ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
			{
		//TYPE_I
		{
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Aqua, Palette::Aqua, Palette::Aqua, Palette::Aqua, Palette::Aqua,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},

		{
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Aqua, Palette::Black, Palette::Black,
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Aqua, Palette::Aqua, Palette::Aqua, Palette::Aqua, Palette::Aqua,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},
	},
	//TYPE_L
	{
		{Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Orange, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Orange, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Orange, Palette::Orange, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black},

		{Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Orange, Palette::Orange, Palette::Orange, Palette::Black,
		Palette::Black, Palette::Orange, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},

		{Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Orange, Palette::Orange, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Orange, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Orange, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},

		{Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Orange, Palette::Black,
		Palette::Black, Palette::Orange, Palette::Orange, Palette::Orange, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black},

	},
	// TYPE_J
	{
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Blue, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Blue, Palette::Black, Palette::Black,
			Palette::Black, Palette::Blue,  Palette::Blue, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Blue, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Blue, Palette::Blue, Palette::Blue, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Blue, Palette::Blue, Palette::Black,
			Palette::Black, Palette::Black, Palette::Blue, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Blue, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Blue, Palette::Blue, Palette::Blue, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Blue, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black
		},
	},
	//TYPE_Z
	{
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Black, Palette::Black, Palette::Black,
		},

		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Lightgreen, Palette::Black, Palette::Black,
			Palette::Black, Palette::Lightgreen, Palette::Black, Palette::Black, Palette::Black,
		},
	},
	//TYPE_S
	{
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Red, Palette::Black,
			Palette::Black, Palette::Red, Palette::Red, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Red, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Red, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Red, Palette::Black,
			Palette::Black, Palette::Red, Palette::Red, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Red, Palette::Red, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Red, Palette::Black,
		},
	},
	//TYPE_O
	{
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black,
			Palette::Black, Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black,
			Palette::Black, Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black, Palette::Black,
			Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black, Palette::Black,
			Palette::Black, Palette::Yellow, Palette::Yellow, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
	},
	//TYPE_T
	{
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Magenta, Palette::Magenta, Palette::Magenta, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Magenta, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Magenta, Palette::Magenta, Palette::Magenta, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
		{
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Magenta, Palette::Black,
			Palette::Black, Palette::Black, Palette::Magenta, Palette::Black, Palette::Black,
			Palette::Black, Palette::Black, Palette::Black, Palette::Black, Palette::Black,
		},
	},

};
Color display[FIELD_HEIGHT][FIELD_WIDTH] = {};
Color field[FIELD_HEIGHT][FIELD_WIDTH] = {};
const static int mino_height[TYPE_MAX][ANGLE_MAX] = { {5, 1, 5, 1}, {3, 2, 3, 1,},  {3, 1, 3, 2},
	{2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2},{2, 3, 2, 3} };
const static int mino_xposl[TYPE_MAX][ANGLE_MAX] = { {2,0,2,0}, {2, 1, 1, 1},
	{1, 1, 2, 1}, {1, 1, 1, 1}, {1, 2, 1, 2}, {2, 2, 1, 1}, {1, 1, 1, 2} };
const static int mino_xposr[TYPE_MAX][ANGLE_MAX] = { {2,0,2,0}, {1, 1, 2, 1},
	{2, 1, 1, 1}, {1, 2, 1, 2}, {1, 1, 1, 1}, {1, 1, 2, 2}, {1, 2, 1, 1} };
const ColorF minoc[TYPE_MAX] = { Palette::Aqua, Palette::Orange, Palette::Blue,
Palette::Lightgreen, Palette::Red, Palette::Yellow, Palette::Magenta };
/// @brief ブロック一個単位のクラス
class Block {
private:
	SizeF size;
public:
	RectF block;
	ColorF color;
	Vec2 dpos;
	/// @brief コンストラクタ
	/// @param _color ブロックの色
	/// @param pos ブロックの描画位置
	/// @param _index ブロックの番号（配列管理用）
	Block(const ColorF& _color, const Vec2& pos) :
		size{ 17, 17 }, color(_color), dpos(pos), block{pos, size} {}
	const Vec2 LeftT()const {
		return Vec2(block.x - size.x - 1, block.y);
	}
	const Vec2 RightT()const {
		return Vec2(block.x + size.x + 1, block.y);
	}
	const Vec2 LeftB()const {
		return Vec2(block.x, block.y + size.y + 1);
	}
	const double x()const {
		return block.x;
	}
	const double y()const {
		return block.y;
	}

};

const Vec2 FIRST_BLOCK_POS = { 400, 100 };

/// @brief ブロック生成
class Blocks {
private:

	Vec2 bpos{0, 0};
	//fx 落下物のX,　fy　落下物のY, px1 左端の空白埋め, px2 右端の空白埋め, py 下の空白埋め 
	int fx, fy, px1, px2, py;

public:
	Blocks() : fx(5), fy(0), px1(0), px2(0), py(0){
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				field[y][x] = Palette::Black;
				display[y][x] = Palette::Black;
			}
		}
	}

	int reset_mino() {
		fx = 5;
		fy = 0;
		return Random((TYPE_I, (TYPE_MAX - 1)));
	}

	bool hit(int tx, int ty, int r, int t) {
		for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (tx + x < FIELD_WIDTH && ty + y < FIELD_HEIGHT) {
					if (mino[t][r][y][x] != Palette::Black) {
						if (field[ty + y + 1][tx + x] != Palette::Black || y + ty == 29)
						{
							if (y + ty == 29) {
								py -= y;
							}
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	void ret_px(int& tx1, int& tx2, int t, int r) {
		bool flag = false;
		for (int x = 0; x < MINO_WIDTH && flag != true; ++x) {
			for (int y = 0; y < MINO_HEIGHT && flag != true; ++y) {
				if (mino[t][r][y][x] != Palette::Black) {
					tx1 = x;
					flag = true;
				}
			}
		}
		flag = false;
		for (int x = MINO_WIDTH - 1; x >= 0 && flag != true; --x) {
			for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
				if (mino[t][r][y][x] != Palette::Black) {
					tx2 = x;
					flag = true;
				}
			}
		}
	}

	
	void move(int& r, int& t, Stopwatch& time, Stopwatch& release, Stopwatch& cd) {

		ret_px(px1, px2, t, r);
		if (KeyZ.down()) {
			int x1 = 0, x2 = 0;
			ret_px(x1, x2, t, (r + 1 > 4) ? 0 : r + 1);
			if (fx < 0 - x1) {
				fx = 0 - x1;
			}
			else if (fx >= FIELD_WIDTH - x2) {
				fx = FIELD_WIDTH - 1 - x2;
			}
			++r;
			if (r > 4) {
				r = 0;
			}
		}
		if (KeyX.down()) {
			int x1 = 0, x2 = 0;
			ret_px(x1, x2, t, (r - 1 < 0) ? 3 : r - 1);
			if (fx < 0 - x1) {
				fx = 0 - x1;
			}
			else if (fx >= FIELD_WIDTH - x2) {
				fx = FIELD_WIDTH - 1 - x2;
			}
			--r;
			if (r < 0) {
				r = 3;
			}
		}

		

		if (KeyA.down() || KeyLeft.down()) {
			bool flag_fx = false;
			for (int x = 0; x < MINO_WIDTH; ++x) {
				for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
					if (field[fy][fx - 1] != Palette::Black && mino[t][r][y][x] != Palette::Black) {
						flag_fx = false;
					}
					else {
						flag_fx = true;
					}
				}
			}
			if (flag_fx == true) {
				--fx;
			}
			if (fx < 0 - px1)
			{
				fx = 0 - px1;
			}

		}
		if (KeyD.down() || KeyRight.down()) {
			bool flag_fx = false;
			for (int x = MINO_WIDTH - 1; x >= 0; --x) {
				for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
					if (field[fy][fx + 1] != Palette::Black && mino[t][r][y][x] != Palette::Black) {
						flag_fx = false;
					}
					else {
						flag_fx = true;
					}
				}
			}
			if (flag_fx == true) {
				++fx;
			}
			if (fx >= FIELD_WIDTH - px2) {
				fx = FIELD_WIDTH - 1 - px2;
			}


		}
		
		bool flag = false;
		for (int y = MINO_HEIGHT - 1; y >= 0 && flag != true; --y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					py = 5 - y;
					flag = true;
				}
			}
		}


		
		if (hit(fx, fy, r, t) == true) {
			int count_x = 0, count_y = 0;
			for (int y = 0; y < 5; ++y) {
				for (int x = 0; x < 5; ++x) {
					if (mino[t][r][y][x] != Palette::Black) {
						if (fx < 15) {
							field[fy + y][fx + x] = mino[t][r][y][x];
						}
						else {
							field[fy + y][fx + x - px2] = mino[t][r][y][x];
						}
					}
				}
			}

			t = reset_mino();
		}
		if (KeyS.pressed() || KeyDown.pressed()) {
			++fy;
			if (hit(fx, fy, r, t) == true) {

			}
		}
		if (time >= 0.5s) {
			++fy;
			time.reset();
		}
		
		
		Print << fx;
		Print << fy;
		Print << time;


	}
	void Draw(int t, int r) {
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				display[y][x] = field[y][x];
			}
		}

		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					display[fy + y][fx + x] = mino[t][r][y][x];
				}
			}
		}
		Array<Block> dsply;
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (display[y][x] != Palette::Black) {
					dsply << Block(display[y][x], Vec2(FIELD_WIDTH_0 + ((x) * 18), FIELD_HEIGHT_0 + (y * 18)));
				}
			}
		}
		for (auto& it : dsply) {
			it.block.draw(it.color);
		}


	}

	void erase_block() {
		int line_count = 0;
		bool Islinefilled = true;
		for (int y = FIELD_HEIGHT - 1; y > 0; ) {
			Islinefilled = true;
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (field[y][x] == Palette::Black) {
					Islinefilled = false;
				}
				else {
					++line_count;
				}
			}
			if (Islinefilled == true) {
				if (y > 0) {
					for (int z = y; z > 0; --z) {
						for (int x = 0; x < FIELD_WIDTH; ++x) {
							field[z][x] = field[z - 1][x];
						}
					}
					for (int x = 0; x < FIELD_WIDTH; ++x) {
						field[0][x] = Palette::Black;
					}
				}
			}
			else
			{
				--y;
			}
		}
	}

	int rand_t() {
		return Random((TYPE_I, (TYPE_MAX - 1)));
	}

};



void Main()
{

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.0, 0.0, 0.0 });
	LineString debug = { Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0), Vec2(FIELD_LINE_WIDTH, FIELD_HEIGHT_0),
		Vec2(FIELD_LINE_WIDTH, FIELD_LINE_HEIGHT), Vec2(FIELD_WIDTH_0, FIELD_LINE_HEIGHT),
		Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0) };
	Blocks block;
	int r = 0, t = block.rand_t();
	Stopwatch time{ StartImmediately::No }, release{ StartImmediately::No }, cd{StartImmediately::No};
	while (System::Update())
	{
		time.start();
		block.move(r, t, time, release, cd);
		block.Draw(t, r);
		block.erase_block();
		debug.draw();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
