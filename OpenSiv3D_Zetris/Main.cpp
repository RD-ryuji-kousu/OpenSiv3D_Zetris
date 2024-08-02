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

char mino[TYPE_MAX][ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
			{
		//TYPE_I
		{
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
		},

		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			1, 1, 1, 1, 1,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0
		},

		{
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
		},

		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			1, 1, 1, 1, 1,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0
		},
	},
	//TYPE_L
	{
		{0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 1, 0,
		0, 0, 0, 0, 0},

		{0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 1, 1, 1, 0,
		0, 1, 0, 0, 0,
		0, 0, 0, 0, 0
		},

		{0, 0, 0, 0, 0,
		0, 1, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 0, 0
		},

		{0, 0, 0, 0, 0,
		0, 0, 0, 1, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0},

	},
	// TYPE_J
	{
		{
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 0, 0, 0,
		},

		{
			0, 0, 0, 0, 0,
			0, 1, 0, 0, 0,
			0, 1, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0
		},

		{
			0, 0, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 0, 0
		},

		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 1, 1, 1, 0,
			0, 0, 0, 1, 0,
			0, 0, 0, 0, 0
		},
	},
	//TYPE_Z
	{
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 1, 0, 0, 0,
		},

		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 1, 0, 0, 0,
		},
	},
	//TYPE_S
	{
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 1, 1, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 1, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 1, 1, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 1, 0,
		},
	},
	//TYPE_O
	{
		{
			0, 0, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 1, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 1, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
		},
	},
	//TYPE_T
	{
		{
			0, 0, 0, 0, 0,
			0, 1, 1, 1, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 1, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 1, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
		},
		{
			0, 0, 0, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 0, 0,
		},
	},

};

char field[FIELD_HEIGHT][FIELD_LINE_WIDTH] = { 0 };
char display[FIELD_HEIGHT][FIELD_LINE_WIDTH] = { 0 };

/// @brief ブロック一個単位のクラス
class Block {
private:
	SizeF size;
	int index;
public:
	RectF block;
	ColorF color;
	Vec2 dpos;
	/// @brief コンストラクタ
	/// @param _color ブロックの色
	/// @param pos ブロックの描画位置
	/// @param _index ブロックの番号（配列管理用）
	Block(const ColorF& _color, const Vec2& pos, int _index) :
		size{ 18, 18 }, color(_color), dpos(pos), block{pos, size}, index(_index) {}
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
	Array<Block> typei;
	Array<Block> typel;
	Array<Block> typej;
	Array<Block> typez;
	Array<Block> types;
	Array<Block> typeo;
	Array<Block> typet;
	Vec2 bpos{0, 0};
	double dx, dy;
	int fx, fy, px1, px2;
public:
	Blocks() : dx(100), dy(100), fx(7), fy(0), px1(0), px2(4){
		
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				typei << Block(ColorF(Palette::Aqua), FIRST_BLOCK_POS, i);
			}
			else {
				typei << Block(ColorF(Palette::Aqua), typei[i - 1].LeftB(), i);
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				typel << Block(ColorF(Palette::Orange), FIRST_BLOCK_POS, i);
			}
			else if (i == 3) {
				typel << Block(ColorF(Palette::Orange), typel[i - 1].RightT(), i);
			}
			else {
				typel << Block(ColorF(Palette::Orange), typel[i - 1].LeftB(), i);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				typej << Block(ColorF(Palette::Blue), FIRST_BLOCK_POS, i);
			}
			else if (i == 3) {
				typej << Block(ColorF(Palette::Blue), typej[2].LeftT(), i);
			}
			else {
				typej << Block(ColorF(Palette::Blue), typej[i - 1].LeftB(), i);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				typez << Block(ColorF(Palette::Lightgreen), FIRST_BLOCK_POS, i);
			}
			else if (i == 2) {
				typez << Block(ColorF(Palette::Lightgreen), typez[i - 1].LeftB(), i);
			}
			else {
				typez << Block(ColorF(Palette::Lightgreen), typez[i - 1].RightT(), i);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				types << Block(ColorF(Palette::Red), FIRST_BLOCK_POS, i);
			}
			else if (i == 2) {
				types << Block(ColorF(Palette::Red), types[i - 1].LeftB(), i);
			}
			else {
				types << Block(ColorF(Palette::Red), types[i - 1].LeftT(), i);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				typeo << Block(ColorF(Palette::Yellow), FIRST_BLOCK_POS, i);
			}
			else if (i == 2) {
				typeo << Block(ColorF(Palette::Yellow), typeo[0].LeftT(), i);
			}
			else {
				typeo << Block(ColorF(Palette::Yellow), typeo[i - 1].LeftB(), i);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				typet << Block(ColorF(Palette::Magenta), FIRST_BLOCK_POS, i);
			}
			else if (i == 3) {
				typet << Block(ColorF(Palette::Magenta), typet[1].LeftB(), i);
			}
			else {
				typet << Block(ColorF(Palette::Magenta), typet[i - 1].LeftT(), i);
			}
		}
	}

	bool hit(int tx, int ty, int r, int t) {
		for (int y = 0; y < MINO_HEIGHT; y++) {
			for (int x = 0; x < MINO_WIDTH; x++) {
				if (tx + x < FIELD_WIDTH && ty + y < FIELD_HEIGHT) {
					if (mino[t][r][y][x] == 1 && (field[ty + y + 1][tx + x + 1] == 1 || y + ty == 29)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	void move(int& tx, int& ty, int& r, int t) {
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
		
		ty += dy * Scene::DeltaTime();
		
		if (KeyA.pressed() || KeyLeft.pressed()) {

			tx -= dx * Scene::DeltaTime();
			--fx;
			if (fx == 0) {
				for (int y = 0; y < 5; ++y) {
					if (mino[t][r][y][px1] == 0) {
						count++;
					}
				}
				if (count == 5) {
					++px1;
				}
			}
			else {
				px1 = 0;
			}
		}count = 0;
		if (KeyD.pressed() || KeyRight.pressed()) {
			
			tx += dx * Scene::DeltaTime();
			if (fx == FIELD_WIDTH - 1) {
				for (int y = 0; y < 5; ++y) {
					if (mino[t][r][y][px2] == 0) {
						++count;
					}
					
				}
				if (count == 5) {
					--px2;
				}
			}
			else {
				px2 = 0;
			}
			++fx;
		}
		if (KeyS.pressed() || KeyDown.pressed()) {
			ty += dy * Scene::DeltaTime();
			++fy;
			if (fy > 29) {
				fy = 29;
			}
		}

		for (int y = 0; y < MINO_HEIGHT; ++y) {
			for (int x = 0; x < MINO_WIDTH; ++x) {

			}
		}
	}

	Array<Block>& Get_typet() {
		return typet;
	}

	void Debug_Draw() {
		for (auto it = typet.begin(); it != typet.end();it++) {
			it->block.draw(it->color);
		}
	}
	
};

void Debug_DrawF() {
	
}

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.0, 0.0, 0.0 });
	LineString debug = { Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0), Vec2(FIELD_LINE_WIDTH, FIELD_HEIGHT_0),
		Vec2(FIELD_LINE_WIDTH, FIELD_LINE_HEIGHT), Vec2(FIELD_WIDTH_0, FIELD_LINE_HEIGHT),
		Vec2(FIELD_WIDTH_0, FIELD_HEIGHT_0) };
	Blocks block;
	double rad = 0_deg;
	while (System::Update())
	{
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
