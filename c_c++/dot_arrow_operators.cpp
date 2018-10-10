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
        //  一般的にはこういうメンバ変数は private にしてセッターやゲッターでアクセスすることが多い
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


// Constructor
//  this はオブジェクトそのもののポインタ
//  this-> は別になくても良い
Human::Human(int age_, double height_, double weight_)
{
    // 人が増えたら人数カウンタを増やす
    people_counter++;

    // set status
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}

Human::~Human()
{
    // 人が減ったら人数カウンタを減らす
    people_counter--;
}

void Human::setStatus(int age_, double height_, double weight_)
{
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}


// 参照渡し
//  const をつけると関数内で引数を変更できない
//  引数を変更したくないときは「参照渡し」のように分けても良いかも
void dotOperator(const Human &human)
{
    std::cout << human.age << ", " << human.height << ", " << human.weight << std::endl;
}

// アドレス渡し
//  逆に引数を関数内で変更する場合は「アドレス渡し」にするとか区別しても良いかも
//      この関数内では変更しないが，
void arrowOperator(Human *human)
{
    std::cout << human->age << ", " << human->height << ", " << human->weight << std::endl;
}


int main()
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << "dot / arrow operators " << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // alice を作成
    Human alice(24, 160, 45);
    std::cout << "<< alice >>" << std::endl;


    // ========================================================================
    // ドット演算子
    // ========================================================================
    // こっちはオブジェクトをそのまま渡す
    std::cout << "dot operator: " << std::endl;
    dotOperator(alice);


    // ========================================================================
    // アロー演算子
    // ========================================================================
    // こっちはアドレスを渡す
    std::cout << "arrow operator: " << std::endl;
    arrowOperator(&alice);


    // ========================================================================
    // クラスの static なメンバ変数
    // ========================================================================
    std::cout << "" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "static member " << std::endl;
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


    // ========================================================================
    // 動的なオブジェクトの生成
    // ========================================================================

    std::cout << "" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "new / delete operators " << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // david を作成
    //  今までの alice, bob, chris は「静的なオブジェクト」として生成される
    //      プログラムが終わるまで（厳密にはそのスコープが終わるまで）メモリから解放されない
    //
    //  そこで「動的なオブジェクト」を生成できる new 演算子の登場
    //  new で作成されたオブジェクトは delete文 がないと削除されない
    //  このオブジェクトはポインタで扱われる
    //  delete を忘れないように（メモリリークの原因となる）
    Human* david = new Human(10, 140, 40);
    std::cout << "<< david >>" << std::endl;
    dotOperator(*david);   // 実体を渡す必要あり
    arrowOperator(david);  // ポインタなのでそのまま渡して良い
    std::cout << "people counter: " << Human::people_counter << std::endl;

    // david を削除（メモリを解放する）
    delete david;
    std::cout << "delete david" << std::endl;
    std::cout << "people counter: " << Human::people_counter << std::endl;

    return 0;
}
