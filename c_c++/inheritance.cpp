// ============================================================================
// クラスの継承について簡単まとめ
// 基底クラスのコンストラクタを派生クラスで呼ぶ
// ============================================================================

#include <iostream>

// ============================================================================
// Playerクラス
// ============================================================================

//  これを継承して，Warriorクラス・Wizard クラスをつくる
class Player
{
    public:
        Player(int level_ = -1,
               double attackPoint_ = -1,
               double defencePoint_ = -1,
               double hitPoint_ = -1,
               double magickPoint_ = -1);
        ~Player();

        // setter
        void setLevel(int level_);
        void setAttackPoint(double attackPoint_);
        void setDefencePoint(double defencePoint_);
        void setHitPoint(double hitPoint_);
        void setMagickPoint(double magickPoint_);

        // getter
        int getLevel();
        double getAttackPoint();
        double getDefencePoint();
        double getHitPoint();
        double getMagickPoint();

        // functions
        void showStatus();

        // これは純粋仮想関数
        //  virtual をつける ("= 0" を忘れないこと)
        //  派生クラスで具体的に定義する
        //  純粋仮装関数を含むクラスはオブジェクトを生成できない
        virtual double attack() = 0;

    private:
        int level;
        double attackPoint;
        double defencePoint;
        double hitPoint;
        double magickPoint;
};

Player::Player(int level_,
               double attackPoint_,
               double defencePoint_,
               double hitPoint_,
               double magickPoint_)
{
    this->setLevel(level_);
    this->setAttackPoint(attackPoint_);
    this->setDefencePoint(defencePoint_);
    this->setHitPoint(hitPoint_);
    this->setMagickPoint(magickPoint_);
}

Player::~Player()
{
    
}

// setter
void Player::setLevel(int level_)
{
    this->level = level_;
}

void Player::setAttackPoint(double attackPoint_)
{
    this->attackPoint = attackPoint_;
}

void Player::setDefencePoint(double defencePoint_)
{
    this->defencePoint = defencePoint_;
}

void Player::setHitPoint(double hitPoint_)
{
    this->hitPoint = hitPoint_;
}

void Player::setMagickPoint(double magickPoint_)
{
    this->magickPoint = magickPoint_;
}

// getter
int Player::getLevel()
{
    return this->level;
}

double Player::getAttackPoint()
{
    return this->attackPoint;
}

double Player::getDefencePoint()
{
    return this->defencePoint;
}

double Player::getHitPoint()
{
    return this->hitPoint;
}

double Player::getMagickPoint()
{
    return this->magickPoint;
}


// functions
void Player::showStatus()
{
    std::cout << "LEV : " << this->getLevel() << std::endl;
    std::cout << "ATK : " << this->getAttackPoint() << std::endl;
    std::cout << "DFE : " << this->getDefencePoint() << std::endl;
    std::cout << "HP  : " << this->getHitPoint() << std::endl;
    std::cout << "MP  : " << this->getMagickPoint() << std::endl;
}


// ============================================================================
// Warriorクラス
// ============================================================================

class Warrior : public Player
{
    public:
        // Warriorクラスのコンストラクタ内でPlayerクラスのコンストラクタを呼ぶ
        Warrior(int level_ = -1,
               double attackPoint_ = -1,
               double defencePoint_ = -1,
               double hitPoint_ = -1,
               double magickPoint_ = -1) : Player(level_,
                                                  attackPoint_,
                                                  defencePoint_,
                                                  hitPoint_,
                                                  magickPoint_)
        {

        }

        // 派生クラスの Warrior で attack() を再定義
        double attack();
};

// Warriorクラスでは attackPoint の値を攻撃値とする
double Warrior::attack()
{
    return this->getAttackPoint();
}

// ============================================================================
// Wizardクラス
// ============================================================================

class Wizard : public Player
{
    public:
        // Warriorクラスのコンストラクタ内でPlayerクラスのコンストラクタを呼ぶ
        //  : {}の中ではなく，:のあとに基底クラスのコンストラクタを記述する
        Wizard(int level_ = -1,
               double attackPoint_ = -1,
               double defencePoint_ = -1,
               double hitPoint_ = -1,
               double magickPoint_ = -1) : Player(level_,
                                                  attackPoint_,
                                                  defencePoint_,
                                                  hitPoint_,
                                                  magickPoint_)
        {

        }

        // 派生クラスの Wizard で attack() を再定義
        double attack();
};

// Wizardクラスでは attackPoint の2倍の値を攻撃値とする
// ただし，magickPoint を消費し，足りなければ攻撃できない
double Wizard::attack()
{
    double currentMagickPoint = this->getMagickPoint();
    if (currentMagickPoint > 0)
    {
        this->setMagickPoint(currentMagickPoint - 1);
        return this->getAttackPoint() * 2;
    }
    else
    {
        return 0;
    }
}


// ============================================================================
// main
// ============================================================================

int main()
{
    Warrior duran(1, 10, 5, 35, 0);
    Wizard angela(1, 7, 2, 20, 5);

    std::cout << "============================================" << std::endl;
    std::cout << "duran" << std::endl;
    std::cout << "============================================" << std::endl;
    duran.showStatus();
    std::cout << "duran attack: " << duran.attack() << std::endl;

    std::cout << "" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "angela" << std::endl;
    std::cout << "============================================" << std::endl;
    angela.showStatus();
    std::cout << "angela attack: " << angela.attack() << std::endl;
    angela.showStatus();
 
    return 0;
}