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
        if (item.name != AGED_BRIE && item.name != BACKSTAGE_PASS)
        {
            if (item.quality > 0)
            {
                if (item.name != SULFURAS)
                {
                    item.quality--;
                }
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality++;

                if (item.name == BACKSTAGE_PASS)
                {
                    if (item.sellIn < 11)
                    {
                        if (item.quality < 50)
                        {
                            item.quality++;
                        }
                    }

                    if (item.sellIn < 6)
                    {
                        if (item.quality < 50)
                        {
                            item.quality++;
                        }
                    }
                }
            }
        }

        if (item.name != SULFURAS)
        {
            item.sellIn--;
        }

        if (item.sellIn < 0)
        {
            if (item.name != AGED_BRIE)
            {
                if (item.name != BACKSTAGE_PASS)
                {
                    if (item.quality > 0)
                    {
                        if (item.name != SULFURAS)
                        {
                            item.quality--;
                        }
                    }
                }
                else
                {
                    item.quality = 0;
                }
            }
            else if (item.quality < 50)
            {
                item.quality++;
            }
        }
    }
}
void GildedRose::updateBACKSTAGE_PASS(Item & item) 
{
    item.sellIn--;
    if(item.sellIn > 5) 
    {
        item.quality += 2;
    }
    else if(item.sellIn <= 0) 
    {
        item.quality = 0;
    }
    else if(item.sellIn < 5) {
        item.quality += 3;
    }
}
