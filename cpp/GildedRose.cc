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
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != AGED_BRIE && items[i].name != BACKSTAGE_PASS)
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != SULFURAS)
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (items[i].name == BACKSTAGE_PASS)
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (items[i].name != SULFURAS)
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name !=AGED_BRIE )
            {
                if (items[i].name != BACKSTAGE_PASS)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != SULFURAS)
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}
