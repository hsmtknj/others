// ============================================================================
// テンプレートクラスについてまとめる
// イテレータ(iterator)も使ってみる
// ============================================================================


#include <iostream>
#include <vector>

// テンプレートクラスは以下のように宣言する
// class でも typename でもどちらでもいいらしい
template<class T> class Human
{
    public:
        Human(T age_, T height_, T weight_);
        ~Human();

    public:
        T age;
        T height;
        T weight;
};

// テンプレートクラスはクラスではないので，以下のように書かないと怒られる．
template <class T> Human<T>::Human(T age_, T height_, T weight_)
{
    this->age = age_;
    this->height = height_;
    this->weight = weight_;
}

template <class T> Human<T>::~Human()
{

}

int main()
{
    // int型なので，小数点は切り捨てられる
    Human<int> IntHuman(25.5, 174.5, 62.5);
    std::cout << IntHuman.age << std::endl;

    // double型はそのまま小数点で表示される
    Human<double> DoubleHuman(25.5, 174.5, 62.5);
    std::cout << DoubleHuman.age << std::endl;

    // 標準テンプレートライブラリ (STL: Standart Template Library) の vector は便利
    std::vector<double> v;
    v.push_back(1.5);
    v.push_back(3.9);
    std::cout << v[0] << std::endl;
    std::cout << v[1] << std::endl;

    // vector クラスの iterator を使ってみる
    std::vector<double>::iterator itr_begin, itr_end, itr;
    itr_begin = v.begin();
    itr_end = v.end();

    for (itr = itr_begin; itr != itr_end; itr++)
    {
        std::cout << *itr << std::endl;
    }

}
