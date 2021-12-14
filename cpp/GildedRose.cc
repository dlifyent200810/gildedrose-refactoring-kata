#include "GildedRose.h"
#include <string>

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

const std::string AGED_BRIE = "Aged Brie";
const std::string BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
const std::string SULFURAS =  "Sulfuras, Hand of Ragnaros";

void GildedRose::updateQuality()
{
    for (Item& item : items)
    {
        if(item.name == AGED_BRIE)
        {
            if (item.quality < 50)
            {
                item.quality++;
            }

            item.sellIn--;
            if (item.sellIn < 0)
            {
                    if (item.quality < 50)
                    {
                        item.quality++;
                    }
            }
        }

        else if (item.name == BACKSTAGE_PASS) 
        {
            if(item.quality < 50)
            {
                item.quality++;

                if (item.sellIn < 11)
                {
                    if(item.sellIn < 6)
                    {
                        item.quality++;
                    }
                    item.quality++;
                }
            }
            item.sellIn--;
            if (item.sellIn < 0)
            {
                item.quality = 0; 
            }
        }

        else if (item.name != SULFURAS) {
            item.sellIn--;
            if (item.quality > 0)
            {
                    item.quality--;
                    if (item.sellIn < 0)
                    {
                                item.quality--;
                    }
            }
        }
    }
}
