#include <string_view>
#include <fstream>
#include <iostream>

class Data{
private:
    std::string myData;
public:
    Data(std::string newData){
        myData = std::move(newData);
    }
    void add(const Data& other){
        myData += other.myData;
    }
    friend std::ostream& operator<<(std::ostream& os, const Data& data){
        os << data.myData;
        return os;
    };
};

class Document
{
private:
    Data myData;
    std::string myTitle;
public:
    Document(std::string newTitle, std::string newData): myData(std::move(newData)){
        myTitle = std::move(newTitle);
    }
    void save(std::string_view fileName) const
    {
        std::ofstream out;
        out.open(std::string(fileName), std::ios::out);
        out << title();
        out << "\n";
        out << data(); // typ Data poprawnie zachowa swoje dane w tej operacji
        out << "\n.\n";
    }
    std::string title() const{
        return myTitle;
    };
    Data data() const{
        return myData;
    }; // typ Data nieistotny dla reszty problemu

    void combine(const Data& other)
    {
        myData.add(other);
        // szczegóły implementacji nie mają znaczenia
    }
};