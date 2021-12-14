#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

static const char *const BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
static const char *const REGULAR = "Foo";
static const char *const BRIE = "Aged Brie";
static const char *const SULFURAS = "Sulfuras, Hand of Ragnaros";

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == REGULAR)
        {
            if (items[i].quality > 0)
            {
                
                items[i].quality--;
            
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality++;

                if (items[i].name == BACKSTAGE_PASS)
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }
                }
            }
        }

        if (items[i].name != SULFURAS)
        {
            items[i].sellIn--;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != BRIE)
            {
                if (items[i].name != BACKSTAGE_PASS)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != SULFURAS)
                        {
                            items[i].quality--;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else if (items[i].quality < 50)
            {
                items[i].quality++;
            }
        }
    }
}
