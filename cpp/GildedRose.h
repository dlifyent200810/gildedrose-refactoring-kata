#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(std::move(name)), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
public:
    std::vector<Item> items;
    explicit GildedRose(std::vector<Item> && items);
    explicit GildedRose(std::vector<Item> const& items);

    void updateQuality();

private:
    void updateBACKSTAGE_PASS(Item & item);
    void updateAGED_BRIE(Item & item);
    void updateREGULAR(Item & item);
};

