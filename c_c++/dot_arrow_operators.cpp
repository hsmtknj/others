// ============================================================================
// ドット・アロー演算子について簡単まとめ
// ついでに static なメンバーも扱う
// ついでに new/delete 演算子も扱う
// ============================================================================

#include<iostream>
#include<stdio.h>

// アクセスする対象としてHumanクラスを作ってみる
class Human
{
    public:
        Human(int age_ = -1, double height_ = -1, double weight_ = -1);
        ~Human();

        // -----------------------------------------------------
        // variables
        // -----------------------------------------------------

        // オブジェクト間で共通の変数
        //  static をつける
        //  static をつけることで実体をもつ
        static int people_counter;

        // Humanクラスのメンバ変数
        //  この変数を dot operetor と arrow operator で呼んでみる
        int age;
        double height;
        double weight;


        // -----------------------------------------------------
        // functions
        // -----------------------------------------------------

        // ステータス設定関数
        void setStatus(int age_, double height_, double weight_);
};

// オブジェクト共通の変数
//  クラス外で再宣言が必要
int Human::people_counter = 0;


Human::Human(int age_, double height_, double weight_)
{
    // increment people counter
    people_counter++;

    // set status
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}

Human::~Human()
{
    // decrement people counter
    people_counter--;
}

void Human::setStatus(int age_, double height_, double weight_)
{
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}


void dotOperator(Human &human)
{
    std::cout << human.age << ", " << human.height << ", " << human.weight << std::endl;
}

void arrowOperator(Human *human)
{
    std::cout << human->age << ", " << human->height << ", " << human->weight << std::endl;
}


int main()
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << "test of operators (dot, arrow) " << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // alice を作成
    Human alice(24, 160, 45);
    std::cout << "<< alice >>" << std::endl;


    // ========================================================================
    // ドット演算子
    // ========================================================================
    //  こっちはオブジェクトをそのまま渡す
    std::cout << "dot operator: " << std::endl;
    dotOperator(alice);


    // ========================================================================
    // アロー演算子
    // ========================================================================
    //  こっちはアドレスを渡す
    std::cout << "arrow operator: " << std::endl;
    arrowOperator(&alice);


    // ========================================================================
    // クラスの static なメンバ変数
    // ========================================================================
    std::cout << "" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "test of a static member " << std::endl;
    std::cout << "-------------------------------" << std::endl;


    // bob を作成
    //  bob から people_counter にアクセス
    Human bob(35, 175, 60);
    std::cout << "<< bob >>" << std::endl;
    dotOperator(bob);
    std::cout << "people counter: " << bob.people_counter << std::endl;

    // chris を作成
    //  クラス自体から people_counter にアクセス
    //  chris はステータスを設定していないので -1 を返す
    Human chris;
    std::cout << "<< chris >>" << std::endl;
    dotOperator(chris);
    std::cout << "people counter: " << Human::people_counter << std::endl;

    // david を作成
    //  new で作成されたオブジェクトは delete文 がないと削除されない
    //  このオブジェクトはポインタで扱われる
    //  delete を忘れないように（メモリリークの原因となる）
    //  alice, bob, chris はそのスコープが終了すると削除される
    Human* david = new Human;
    std::cout << "<< david >>" << std::endl;
    dotOperator(*david);
    std::cout << "people counter" << Human::people_counter << std::endl;

    // david を削除
    delete david;
    std::cout << "delete david" << std::endl;
    std::cout << "people counter: " << Human::people_counter << std::endl;

    return 0;
}


