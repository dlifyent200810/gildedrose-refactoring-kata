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
        if (item.name != AGED_BRIE && item.name != BACKSTAGE_PASS)
        {
            if (item.quality > 0 && item.name != SULFURAS)
            {
                    item.quality--;
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality++;

                if (item.name == BACKSTAGE_PASS)
                {
                    if (item.sellIn < 11 && item.quality < 50)
                    {
                        if(item.sellIn < 6)
                        {
                            item.quality++;
                        }
                        item.quality++;
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
            if (item.name !=AGED_BRIE )
            {
                if (item.name != BACKSTAGE_PASS)
                {
                    if (item.quality > 0 && item.name != SULFURAS)
                    {
                            item.quality--;
                    }
                }
                else
                {
                    item.quality = 0;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.quality++;
                }
            }
        }
    }
}
