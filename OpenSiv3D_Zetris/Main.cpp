 // Siv3D v0.6.14

#include "stdafx.h";

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
			Palette::Black, Palette::Blue, Palette::Blue, Palette::Black, Palette::Black,
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
Color display[FIELD_HEIGHT][FIELD_WIDTH] = { Palette::Black };
Color field[FIELD_HEIGHT][FIELD_WIDTH] = { Palette::Black };

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
		size{ 18, 18 }, color(_color), dpos(pos), block{pos, size} {}
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
	double dx, dy;
	int fx, fy, px1, px2;

public:
	Blocks() : dx(100), dy(100), fx(3), fy(0), px1(0), px2(4){
	}

	int reset_mino() {
		fx = 5;
		fy = 0;
		return Random((TYPE_I, (TYPE_MAX - 1)));
	}

	bool hit(int tx, int ty, int r, int t) {
		for (int y = 0; y < MINO_HEIGHT; y++) {
			for (int x = 0; x < MINO_WIDTH; x++) {
				if (tx + x < FIELD_WIDTH && ty + y < FIELD_HEIGHT) {
					if (mino[t][r][y][x] != Palette::Black &&
						(field[ty + y + 1][tx + x] != Palette::Black || y + ty == 29)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	void put_minos(int &r, int t) {
		for (int y = 0; y <= 5; ++y) {
			for (int x = 0; x <= 5; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					display[y][2 + x] = mino[t][r][y][x];
				}
			}
		}
	}

	void move(int& r, int t, Stopwatch& time, bool& put_mino) {
		if (put_mino == false) {
			put_minos(r, t);
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (field[0][x] != Palette::Black) {
					fx = x;
				}
			}
			put_mino = true;
		}
		if (put_mino == true) {
			int count = 0;
			if (KeyZ.down()) {
				++r;
				if (r > 4) {
					r = 0;
				}
			}
			if (KeyX.down()) {
				--r;
				if (r < 0) {
					r = 3;
				}
			}

			if (time >= 0.5s) {
				fy++;
				time.reset();
			}

			if (KeyA.pressed() || KeyLeft.pressed()) {

				--fx;
				if (fx < 0)
				{
					fx = 0;
				}
				if (fx == 0) {
					/*
					for (int y = 0; y < 5; ++y) {
						if (mino[t][r][y][px1] == 0) {
							count++;
						}
					}
					*/
					if (count == 5) {
						++px1;
					}
				}
				/*
				else {
					px1 = 0;
				}*/
			}count = 0;
			if (KeyD.pressed() || KeyRight.pressed()) {
				++fx;
				if (fx >= FIELD_WIDTH) {
					fx = FIELD_WIDTH - 1;
				}
				if (fx == FIELD_WIDTH - 1) {
					/*
					for (int y = 0; y < 5; ++y) {
						if (mino[t][r][y][px2] == 0) {
							++count;
						}

					}
					if (count == 5) {
						--px2;
					}*/
				}
				/*
				else {
					px2 = 0;
				}*/

			}
			if (KeyS.pressed() || KeyDown.pressed()) {

				++fy;
				if (fy > 29) {
					fy = 29;
				}
			}


			if (hit(fx, fy, r, t) == true) {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						if (fy + y < FIELD_HEIGHT && fx + x < FIELD_WIDTH && x + px1 + px2 > MINO_WIDTH && x + px1 + px2 < 0) {
							field[fy + y][fx + x] = mino[t][r][y][x + px1 + px2];
						}
					}
				}
				reset_mino();
				put_mino = false;
			}
		}
	}
	void Draw(int t, int r) {
		memcpy(display, field, sizeof(display));

		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				display[fy + y][fx + x] = mino[t][r][y][x + px1 + px2];
			}
		}
		Array<Block> dsply;
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (display[y][x] != Palette::Black) {
					dsply << Block(display[y][x], Vec2(FIELD_WIDTH_0 + (x * 18), FIELD_HEIGHT_0 + (y * 18)));
				}
			}
		}
		for (auto& it : dsply) {
			it.block.draw(it.color);
		}


	}

	void erase_block() {
		for (int y = 0; y < FIELD_HEIGHT - 1; ++y) {
			bool Islinefilled = true;
			for (int x = 0; x < FIELD_WIDTH - 1; ++x) {
				if (Palette::Black != field[y][x]) {
					Islinefilled = false;
				}
			}
			if (Islinefilled == true) {
				Color tmp[FIELD_HEIGHT][FIELD_WIDTH] = { Palette::Black };
				std::memcpy(&tmp, &field, sizeof(tmp));
				for (int x = 0; x < FIELD_WIDTH - 1; ++x) {
					field[y][x] = Palette::Black;
					field[y][x] = tmp[y - 1][x];
				}
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
	bool put_mino = false;
	Stopwatch time{ StartImmediately::No };
	while (System::Update())
	{
		time.start();
		block.move(r, t, time, put_mino);
		block.Draw(t, r);
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
