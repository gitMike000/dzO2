#include <iostream>
#include <string>
#include <vector>

enum gen {M = 0, F = 1};

class Person
{
private:
    std::string Name;
    unsigned int Age;
    gen Gender;
    unsigned int Weight;
public:
    Person(std::string name, unsigned char age, gen gender, unsigned char weight)
     { setName(name);
       setAge(age);
       setGender(gender);
       setWeight(weight);
     };
    void setName(std::string name) {Name=name;};
    std::string getName() {return Name;};
    void setAge(unsigned char age) {Age=age;};
    unsigned int getAge() {return Age;};
    void setGender(gen gender) {Gender=gender;};
    gen getGender() {return Gender;};
    void setWeight(unsigned char weight) {Weight=weight;};
    unsigned int getWeight() {return Weight;};
 //   ~Person() {};
};

class Student: public Person
{
private:
    int Year;
public:
    Student(std::string name, unsigned char age, gen gender, unsigned char weight,int year) :  Person(name, age, gender, weight) , Year(year)
    {
    };
    void setYear(int year) {Year=year;};
    void incYear() {Year++;};
    int getYear() {return Year;};
//    ~Student() {};
};

class Fruit
{
private:
   std::string name;
   std::string color;
public:
   Fruit(std::string Name, std::string Color)
   {
       setName(Name);
       setColor(Color);
   };
   void setName(std::string Name) {name=Name;};
   std::string getName() {return name;};
   void setColor(std::string Color) {color=Color;};
   std::string getColor() {return color;};
};

class Apple: public Fruit
{
public:
    Apple(std::string Color): Fruit("apple",Color)
    {};
};


class Banana: public Fruit
{
 public:
    Banana(): Fruit("banana","yellow")
    {};
};

class GrannySmith: public Apple
{
 public:
    GrannySmith(): Apple("green")
    {
        setName("Granny Smith " + getName());
    };
};

int main()
{
    // Task 1
    std::cout << "Task 1\n";
    std::vector <Student> Students;
    Students.push_back(Student("Mark",20,M,56,2021));
    Students.push_back(Student("Helene",23,F,46,2017));
    Students.push_back(Student("Roman",21,M,60,2019));
    std::cout << "Number of students" << (int) Students.size() << '\n';
    std::cout << "Student 1 " << Students[1].getName() << ", year of admission " << Students[1].getYear() << '\n';

    // Task 2
    std::cout << "\nTask 2\n";

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    // Task 3
    std::cout << "\nTask 3\n";
    std::cout << "See code\n";

//    Игрок
//    Играющий за столом против казино.
//    Дилер "Крупье"
//    Работник казино, выполняющий роль чесальщика колоды.
//    Рука
//    Набор карт игрока или дилера. Обычно правилами казино игрокам запрещается прикасаться к своим картам.
//    Трекинг (Tracking)
//    Отслеживание игроком расположения карт в процессе игры, с использованием этой информации на следующем шаффле.
//    Шаффл (Shuffle)
//    Полный «игровой цикл», начинающийся с замешивания колоды, и заканчивающийся выходом разрезной карты.
//    Башмак, шуз (англ. shoe — ботинок)
//    Специальное приспособление для карточных игр в казино. Колода перемешивается и вставляется в шуз, из которого потом идет раздача карт.
//    Фишка (англ. chip)
//    Плоский небольшой предмет круглой, квадратной или восьмиугольной формы, на котором написан его номинал, может обмениваться на наличные деньги в кассе казино.


//    class Card
//    {
//    public:
//      enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
//               JACK, QUEEN, KING};  // значение карты
//      enum suit {CLUBS, DIAMONDS, HEARTS, SPADES}; // масть

//      Card();

//      //возвращает значение карты 1 - 11
//      int GetValue() const;

//      //переворот карты - лицо - спина
//      void Flip();

//    private:
//      rank m_Rank;
//      suit m_Suit;
//      bool m_IsFaceUp;
//    };


//    class Hand
//    {
//    public:
//      Hand();


//      //взять карту в руку
//      void Add();

//      //убрать карты из руки
//      void Clear();

//      //получаем общее значение руки, правильно трактуем туз как 1 или 11
//      int GetTotal() const;

//    protected:
//      vector <Card*> m_Cards; // набор карт
//    };

//     //Базовый игрок
//    class GenericPlayer : public Hand
//    {

//    public:
//      GenericPlayer(string name);

//      //игрок продолжает бить
//      bool IsHitting(); //pure virtual function

//      //Проверка на кол-во очков > 21
//      bool IsBusted();

//      //Игрок вылетает?
//      void Bust();

//    protected:
//      string m_Name; // Имя игрока
//    };

//    // Обычный игрок
//    class Player : public GenericPlayer
//    {
//    public:
//      Player(string name);

//      bool IsHitting() const;

//      //Игрок выиграл
//      void Win();

//      //Игрок проиграл
//      void Lose();

//      //Игрок берет карту
//      void Push();
//    };

//    // Дилер
//    class Diler : public GenericPlayer
//    {
//      public:
//        Diler(string name = "Direl");

//        //Бьет Дилер
//        bool IsHitting();

//        //Переворот первой карты
//        void FlipFirstCard();
//    };

//    // Башмак
//    class Shoes : public Hand
//    {
//      public:
//        Shoes();

//        //Создает колоду на SIZE карт
//        void Populate();

//        //Запуск игрового процесса
//        void Shuffle();

//        //Сдает одну карту в руку
//        void Deal();

//        // дает игроку дополнительную карту
//        // до тех пор, пока они продолжают нажимать
//        void AdditionalCards();
//    };


//    // Игра
//    class Game
//    {
//    public:
//        Game(vector<string> names);

//        //запуск игры
//        void Play();

//    private:
//        Shoes m_Shoes;
//        Diler m_Diler;
//        vector<Player> m_Players;
//    };

// Сколько будет классов в программе? 7
//
//  Какие классы будут базовыми, а какие производными?
// базовые Card, Hand, GenericPlayer, Game
// производные   Player, Diler, Shoes


}
