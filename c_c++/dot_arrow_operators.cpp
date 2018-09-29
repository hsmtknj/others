// ============================================================================
// ドット・アロー演算子について簡単まとめ
// ============================================================================

#include<iostream>
#include<stdio.h>

// アクセスする対象としてHumanクラスを作ってみる
class Human
{
    public:
        Human(int age_, double height_, double weight_);
        ~Human();

        // functions
        // ステータス設定関数
        void setStatus(int age_, double height_, double weight_);

        // variables
        // Humanクラスのメンバ変数
        // この変数を dot operetor と arrow operator で呼んでみるよ
        int age;
        double height;
        double weight;
};

Human::Human(int age_, double height_, double weight_)
{
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}

Human::~Human()
{

}

void Human::setStatus(int age_, double height_, double weight_)
{
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}


void dotOperator(Human &human)
{
    std::cout << "dot operator: " << std::endl;
    std::cout << human.age << ", " << human.height << ", " << human.weight << std::endl;
}

void arrowOperator(Human *human)
{
    std::cout << "arrow operator: " << std::endl;
    std::cout << human->age << ", " << human->height << ", " << human->weight << std::endl;
}


int main()
{
    // 人間をひとり作成
    Human human(24, 160, 45);


    // ========================================================================
    // ドット演算子
    // ========================================================================
    //  こっちはオブジェクトをそのまま渡す
    dotOperator(human);


    // ========================================================================
    // アロー演算子
    // ========================================================================
    //  こっちはアドレスを渡す
    arrowOperator(&human);

    // ステータスを変えてみる
    human.setStatus(35, 170, 60);
    arrowOperator(&human);

    return 0;
}


