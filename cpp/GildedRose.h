#include <string>
#include <vector>

class Item
{
public:
    ::std::string name;
    int sellIn;
    int quality;
    Item(::std::string name, int sellIn, int quality) : name(::std::move(name)), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
private:
    const int fifty = 50;
    const string AB = "Aged Brie";
    const string BPTATC = "Backstage passes to a TAFKAL80ETC concert";
    const string SHOR = "Sulfuras, Hand of Ragnaros";
    void increaseItemAtIndexByOne(int sellInOfItem); 

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items);
    explicit GildedRose(::std::vector<Item> const& items);
    
    void updateQuality();
};
