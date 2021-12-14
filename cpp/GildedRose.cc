#include "GildedRose.h"

constexpr auto BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
constexpr auto AGED_BRIE = "Aged Brie";
constexpr auto SULFURAS = "Sulfuras, Hand of Ragnaros";

GildedRose::GildedRose(std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(std::vector<Item> && items) : items(std::move(items))
{}

void GildedRose::updateQuality()
{
    for (auto& item : items)
    {
        if(item.name == BACKSTAGE_PASS) 
        {
            updateBACKSTAGE_PASS(item);
        }
        else if(item.name == AGED_BRIE)
        {
            updateAGED_BRIE(item);
        }
        else if(item.name == SULFURAS)
        {
            // do nothing
        }
        else
        {
            updateREGULAR(item);
        }
    }
}
void GildedRose::updateBACKSTAGE_PASS(Item & item) 
{
    if(item.sellIn >= 6) 
    {
        item.quality += 2;
    }
    else if(item.sellIn <= 0) 
    {
        item.quality = 0;
    }
    else if(item.sellIn <= 5) {
        item.quality += 3;
    }
    item.sellIn--;
}
void GildedRose::updateAGED_BRIE(Item & item) 
{
    if(item.sellIn > 0) 
    {
        item.quality++;
    }
    else if(item.sellIn == 0) 
    {
        item.quality += 2;
    }
    else if(item.sellIn < 0) 
    {
        item.quality += 2;
    }
    // cap quality at 50
    if(item.quality >= 50) 
    {
        item.quality = 50;
    }
    item.sellIn--;
}
void GildedRose::updateREGULAR(Item & item) 
{
    if(item.sellIn > 0)
    {
        item.quality--;
    }
    else if(item.sellIn <= 0)
    {
        item.quality -= 2;
    }

    // cap quality at 0
    if(item.quality <= 0)
    {
        item.quality = 0;
    }
    item.sellIn--;
}
