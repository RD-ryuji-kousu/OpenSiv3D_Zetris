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

inline int r1(int r) {
	return (r + 1 > 4) ? 0 : r + 1;
}
inline int r2(int r) {
	return (r - 1 < 0) ? 3 : r - 1;
}

//ミノの形管理index用
enum minotype {
	TYPE_I, TYPE_L, TYPE_J, TYPE_Z, TYPE_S,
	TYPE_O, TYPE_T, TYPE_MAX
};
//ミノのアングル管理index用
enum minoangle {
	ANGLE_0, ANGLE, _90, ANGLE_180, ANGLE_270, ANGLE_MAX
};
//ミノの実体配列
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
//ミノの画面表示
Color display[FIELD_HEIGHT][FIELD_WIDTH] = {};
//固定されたミノ管理
Color field[FIELD_HEIGHT][FIELD_WIDTH] = {};


//スタート画面
class Start {
public:
	void View() {
		font(first).draw(Arg::center(400, 200));
	}
private:
	const Font font{ 60 };
	String first = U"Start press 'F'";
};

//ゲームオーバー画面
class Over {
public:
	/*
	@param[in] text1	条件に則したテキストを受け取る
	*/
	void View() {
		title(text1).draw(Arg::center(400, 100), Palette::Red);
		font(restart).draw(Arg::center(400, 400));
		font(quit).draw(Arg::center(400, 500));
	}
private:
	const Font title{ 100 };
	const Font font{ 60 };
	String text1 = U"Missed!!";
	String restart = U"Restart Press'R'";
	String quit = U"Quit Press 'Q'";
};



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

};


/// @brief ブロック生成
class Blocks {
private:

	Vec2 bpos{0, 0};
	//fx 落下物のX,　fy　落下物のY, px1 左端の空白埋め, px2 右端の空白埋め, py 下の空白埋め 
	int fx, fy, px1, px2, py1, py2, pyu;
	bool put_flag;
public:
	/// @brief コンストラクタ及びfield,displayの初期化
	Blocks() : fx(5), fy(0), px1(0), px2(0), py1(0), py2(0), pyu(0), put_flag(false){
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				field[y][x] = Palette::Black;
				display[y][x] = Palette::Black;
			}
		}
	}

	/// @brief ミノの初期位置を設定しランダムに形を設定
	/// @return ミノの形をランダムに返す
	int reset_mino() {
		int t = Random((TYPE_I, (TYPE_MAX - 1))), ty1 = 0, ty2 = 0;
		ret_py(ty1, ty2, t, 0);
		fx = 5;
		fy = 0 - ty1;
		return t;
	}

	/*
	minoの空白ではない、中身のある部分を得る。
	@param[out]  x0  左端の位置(0～4)を得る
	@param[out]  y0  上端の位置(0～4)を得る
	@param[out]  x1  右端の位置(0～4)を得る
	@param[out]  y1  下端の位置(0～4)を得る
	*/
	void get_contents(int t, int r, int& x0, int& y0, int& x1, int& y1) const {
		x0 = MINO_WIDTH, y0 = MINO_HEIGHT;
		x1 = -1, y1 = -1;
		for (int y = 0; y < MINO_HEIGHT; ++y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					if (x0 > x) {
						x0 = x;
					}
					if (y0 > y) {
						y0 = y;
					}
					if (x1 < x) {
						x1 = x;
					}
					if (y1 < y) {
						y1 = y;
					}
				}
			}
		}
	}

	/*
	minoをフィールド(fx,fy)に配置できるかを判定する。
	@param[in] fx, fy フィールド上のminoの左上の座標
	@param[in]t, rミノの形とアングル
	@return 各領域との交差判定を返す。
				  bit0  minoの中身がフィールドの左側にはみ出していたら1
				  bit1  minoの中身がフィールドの上側にはみ出していたら1
				  bit2  minoの中身がフィールドの右側にはみ出していたら1
				  bit3  minoの中身がフィールドの下側にはみ出していたら1
	@note この関数では、フィールドに配置された物体との衝突は見ない。
　　　　フィールドからはみ出しているか否かのみを判定する。
	*/
	int determine_field_boundary(int t, int r, int tx , int ty) const {
		int ret_val = 0;
		int x0, x1, y0, y1;
		get_contents(t, r, x0, y0, x1, y1);
		if (tx + x0 < 0) {
			ret_val |= (1 << 0);
		}
		if (ty + y0 < 0) {
			ret_val |= (1 << 1);
		}
		if (tx + x1 >= FIELD_WIDTH) {
			ret_val |= (1 << 2);
		}
		if (ty + y1 >= FIELD_HEIGHT) {
			ret_val |= (1 << 3);
		}
		return ret_val;
	}



	bool is_collision_field(int tx, int ty, int t, int r)const {
		for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (mino[t][r][y][x] != Palette::Black && field[ty + y][tx + x] != Palette::Black) {
					return true;
				}
			}
		}
		return false;
	}

	void put_mino(int& t, int r, int tx, int ty, Stopwatch& release, String& game) {
		bool hitf = false;
		for (int x = 0; x < FIELD_WIDTH; ++x) {
			if (field[0][x] != Palette::Black) {
				game = U"over";
			}
		}
		for (int y = 0; y < MINO_HEIGHT; ++y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (mino[t][r][y][x] != Palette::Black && release >= 0.5s) {
					field[ty + y][tx + x] = mino[t][r][y][x];
					hitf = true;
				}
				else if (mino[t][r][y][x] != Palette::Black && release <= 0s) {
					release.start();
				}
			}
		}
		//次のミノを呼び出す
		if (hitf == true) {
			release.reset();
			t = reset_mino();
			put_flag = false;
		}
	}

	/// @brief ミノが底辺もしくは、他のミノとぶつかった時true
	/// @param[in] r ミノのアングル
	/// @param[in] t ミノの形
	/// @return ミノが底辺と他ミノとhitしたか否かをtrue,falseで返す
	bool hit(int r, int t) {
		for (int y = MINO_HEIGHT - 1; y >= 0; --y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					
					if (field[fy + y][fx + x] != Palette::Black) {
						fy -= 1;
					}
					if (field[fy + y + 1][fx + x] != Palette::Black || y + fy >= FIELD_HEIGHT - 1)
					{
						if (y + fy >= FIELD_HEIGHT) {
							fy = (FIELD_HEIGHT - 1) - pyu; //yが底辺を超えたら補正する
						}
						return true;
					}
						

				}
				
			}
		}
		return false;
	}

	
	/// @brief ミノの両端を調べる
	/// @param[in, out] tx1 ミノの左端
	/// @param[in,out] tx2 ミノの右端
	/// @param[in] t ミノの形 
	/// @param[in] r ミノのアングル
	void ret_px(int& tx1, int& tx2, int t, int r) {
		bool flag = false;
		//ミノの左端を調べる
		for (int x = 0; x < MINO_WIDTH && flag != true; ++x) {
			for (int y = 0; y < MINO_HEIGHT && flag != true; ++y) {
				if (mino[t][r][y][x] != Palette::Black) {
					tx1 = x;
					flag = true;	// 見つけたらループを抜ける
				}
			}
		}
		flag = false;
		//ミノの右端を調べる
		for (int x = MINO_WIDTH - 1; x >= 0 && flag != true; --x) {
			for (int y = MINO_HEIGHT - 1; y >= 0 && flag != true; --y) {
				if (mino[t][r][y][x] != Palette::Black) {
					tx2 = x;
					flag = true;	 //見つけたらループを抜ける
				}
			}
		}
	}

	/// @brief ミノの上端、下端を調べる
	/// @param[out] ty1 ミノの上端
	/// @param[out] ty2 ミノの下端
	/// @param[in] t ミノの形
	/// @param[in] r ミノのアングル
	void ret_py(int& ty1, int& ty2, int t, int r) {
		bool flag = false;
		for (int y = 0; y < MINO_HEIGHT && flag != true; ++y) {
			for (int x = 0; x < MINO_WIDTH && flag != true; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					ty1 = y;
					flag = true;
				}
			}
		}
		flag = false;
		for (int y = MINO_HEIGHT - 1, count = 0; y >= 0 && flag != true; --y, ++count) {
			for (int x = 0; x < MINO_WIDTH && flag != true; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					ty2 = y;
					pyu = count;
					flag = true;
				}
			}
		}
	}



	/// @brief ミノの動き及び、処理
	/// @param[in, out] r ミノのアングル
	/// @param[in, out] t ミノの形
	/// @param[in, out] time ミノの落ちる間隔の管理
	/// @param[in, out] release ミノのがぶつかってから操作出来る時間の管理
	/// @param[in, out] game ゲームのステート
	void move(int& r, int& t, Stopwatch& time, Stopwatch& release, String& game) {
		
		ret_px(px1, px2, t, r);
		//Zを押したときアングルを90°正回転
		if (KeyZ.down()) {
			int d = determine_field_boundary(t, r1(r), fx, fy);
			//回転後の左端x1,右端x2
			/*int x1 = 0, x2 = 0;
			ret_px(x1, x2, t, (r + 1 > 4) ? 0 : r + 1);*/
			//回転後端を超えてしまう場合補正
			/*
			if (fx < 0 - x1) {
				fx = 0 - x1;
			}
			else if (fx >= FIELD_WIDTH - x2) {
				fx = FIELD_WIDTH - 1 - x2;
			}*/
			if (d == 0 &&
				is_collision_field(fx, fy, t, r1(r)) == false) {
				++r;
			}
			else if (d != 0 &&
				is_collision_field(fx, fy, t, r1(r)) == false) {
				int tx = fx, ty = fy;
				while ((d= determine_field_boundary(t, r1(r), fx, fy)) != 0) {
					
					if ((d & (1 << 0)) != 0) {
						++tx;
					}
					if ((d & (1 << 1)) != 0) {
						++ty;
					}
					if ((d & (1 << 2)) != 0) {
						--tx;
					}
					if ((d & (1 << 3)) != 0) {
						--ty;
					}
				}
				if (is_collision_field(tx, ty, t, r1(r)) == false) {
					fx = tx;
					fy = ty;
					++r;
				}
			}
			//rは常に0～3
			if (r > 3) {
				r = 0;
			}
		}
		//Xを押したとき90°逆回転
		if (KeyX.down()) {
			/*
			int x1 = 0, x2 = 0;
			ret_px(x1, x2, t, (r - 1 < 0) ? 3 : r - 1);
			if (fx < 0 - x1) {
				fx = 0 - x1;
			}
			else if (fx >= FIELD_WIDTH - x2) {
				fx = FIELD_WIDTH - 1 - x2;
			}*/

			int d = determine_field_boundary(t, r2(r), fx, fy);
			if (d == 0 &&
				is_collision_field(fx, fy, t, r2(r)) == false) {
				--r;
			}
			else if (d != 0 && is_collision_field(fx, fy, t, r2(r)) == false) {
				int tx = fx, ty = fy;
				while ((d = determine_field_boundary(t, r2(r), fx, fy)) != 0) {
					if ((d & (1 << 0)) != 0) {
						++tx;
					}
					if ((d & (1 << 1)) != 0) {
						++ty;
					}
					if ((d & (1 << 2)) != 0) {
						--tx;
					}
					if ((d & (1 << 3)) != 0) {
						--ty;
					}
				}
				if (is_collision_field(tx, ty, t, r2(r)) == false) {
					fx = tx;
					fy = ty;
					++r;
				}
			}
			if (r < 0) {
				r = 3;
			}
		}

		
		//Aか←キーで左移動
		if (KeyA.down() || KeyLeft.down()) {		
			//移動先に石がなければ移動
			if (determine_field_boundary(t, r, fx - 1, fy) ==  0 &&
				is_collision_field(fx - 1, fy, t, r) == false) {
				--fx;
				if (release > 0s) {
					if (determine_field_boundary(t, r, fx, fy - 1) == 0 &&
						is_collision_field(fx, fy - 1, t, r) == false) {
						release.reset();
						time.restart();
					}
				}
			}


			//ミノの左端を考慮した上で画面左端を超えないよう補正
			if (fx < 0 - px1)
			{
				fx = 0 - px1;
			}

		}
		//Dか→キーで右移動
		if (KeyD.down() || KeyRight.down()) {			
			if (determine_field_boundary(t, r, fx + 1, fy) == 0 &&
				is_collision_field(fx + 1, fy, t, r) == false) {
				++fx;
				if (release > 0s) {
					if (determine_field_boundary(t, r, fx, fy - 1) == 0 &&
						is_collision_field(fx, fy - 1, t, r) == false) {
						release.reset();
						time.restart();
					}
				}
			}
			if (fx >= FIELD_WIDTH - px2) {
				fx = FIELD_WIDTH - 1 - px2;
			}


		}

		/*
		ret_py(py1, py2, t, r);

		//衝突判定
		if (hit(r, t) == true) {
			bool hitf = false;
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (field[0][x] != Palette::Black) {
					game = U"over";
				}
			}
			//ミノが他ミノと衝突及び画面一番下に到達時、0.5秒の回転操作及び左右移動の猶予を与える
			for (int y = 0; y < MINO_HEIGHT; ++y) {
				for (int x = 0; x < MINO_WIDTH; ++x) {
					if (mino[t][r][y][x] != Palette::Black && release >= 0.5s) {
						field[fy + y][fx + x] = mino[t][r][y][x];
						hitf = true;
					}
					else if (mino[t][r][y][x] != Palette::Black && release <= 0s) {
						release.start();
					}
				}
			}
			//次のミノを呼び出す
			if (hitf == true) {
				release.reset();
				t = reset_mino();
			}
		}
		*/
		//時間ごとのミノの下降
		if (time >= 0.5s && release <= 0s) {
			if (determine_field_boundary(t, r, fx, fy + 1) == 0 &&
				is_collision_field(fx, fy + 1, t, r) == false) { 
				++fy;
				time.reset();
			}
			else {
				put_flag = true;
			}
		}

		//Sか↓キーで急下降
		if (release <= 0s && (KeyS.pressed() || KeyDown.pressed())) {
			if (determine_field_boundary(t, r, fx, fy + 1) == 0 &&
				is_collision_field(fx, fy + 1, t, r) == false) {
				++fy;
			}
			else {
				put_flag = true;
			}
		}
		
		if (put_flag == true) {
			put_mino(t, r, fx, fy, release, game);
			
		}
		
	
	}
	/// @brief ミノの描画
	/// @param[in] t ミノの形
	/// @param[out] r ミノのアングル
	void Draw(int t, int r) {
		//fieldをdisplayにコピー
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				display[y][x] = field[y][x];
			}
		}
		//ミノの落下位置のコピー
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				if (mino[t][r][y][x] != Palette::Black) {
					display[fy + y][fx + x] = mino[t][r][y][x];
				}
			}
		}
		Array<Block> dsply;
		//ブロックテクスチャの生成
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (display[y][x] != Palette::Black) {
					dsply << Block(display[y][x], Vec2(FIELD_WIDTH_0 + ((x) * 18), FIELD_HEIGHT_0 + (y * 18)));
				}
			}
		}
		//フィールドの描画
		for (auto& it : dsply) {
			it.block.draw(it.color);
		}


	}
	/// @brief　行が埋まった列を削除して下へ整列
	void erase_block(int& score) {
		bool Islinefilled = true;
		//fieldをチェック
		for (int y = FIELD_HEIGHT - 1; y > 0; ) {
			Islinefilled = true;
			//列が埋まっていたらtrue
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				if (field[y][x] == Palette::Black) {
					Islinefilled = false;
				}
			}
			if (Islinefilled == true) {
				if (y > 0) {
					//一列消して掘り下げる
					for (int z = y; z > 0; --z) {
						for (int x = 0; x < FIELD_WIDTH; ++x) {
							field[z][x] = field[z - 1][x];
						}
					}
					//一番上を黒で埋める
					for (int x = 0; x < FIELD_WIDTH; ++x) {
						field[0][x] = Palette::Black;
					}
					score += 1000;
				}
			}
			//掘り下げ処理がない場合yをデクリメント
			else
			{
				--y;
			}
		}
	}
	//ランダムにミノの形のインデックスを返す
	int rand_t() {
		int t =  Random((TYPE_I, (TYPE_MAX - 1))), ty1 = 0, ty2 = 0;
		ret_py(ty1, ty2, t, 0);
		fy = -ty1;
		return t;
	}
	void reset() {
		for (int y = 0; y < FIELD_HEIGHT; ++y) {
			for (int x = 0; x < FIELD_WIDTH; ++x) {
				field[y][x] = Palette::Black;
				display[y][x] = Palette::Black;
			}
		}
	}
};



void Main()
{

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.0, 0.0, 0.0 });
	LineString debug = { Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0), Vec2(FIELD_LINE_WIDTH, FIELD_HEIGHT_0),
		Vec2(FIELD_LINE_WIDTH, FIELD_LINE_HEIGHT), Vec2(FIELD_WIDTH_0, FIELD_LINE_HEIGHT),
		Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0) };
	Start start;
	Over over;
	Blocks block;
	int r = 0, t = block.rand_t(), score = 0;
	Stopwatch time{ StartImmediately::No }, release{ StartImmediately::No };
	String game = U"start";
	Font font{ 40 };
	while (System::Update())
	{
		if (game == U"start") {
			start.View();
			if (KeyF.pressed()) {
				game = U"game";
			}
		}
		if (game == U"game") {
			time.start();
			block.move(r, t, time, release, game);
			block.Draw(t, r);
			block.erase_block(score);
			font(U"Score", score).draw();
			debug.draw();
		}
		if (game == U"over") {
			over.View();
			if (KeyR.pressed()) {
				block.reset();
				r = 0;
				t = block.rand_t();
				score = 0;
				game = U"game";
			}
			if (KeyQ.pressed()) {
				System::Exit();
			}
		}
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
