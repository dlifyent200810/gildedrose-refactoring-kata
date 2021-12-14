#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::qulityIncrement(const int &i)
{
    items[i].quality = items[i].quality + 1;
}

void GildedRose::negativeSellIn(const int &i)
{
    if (items[i].name == "Aged Brie")
    {
        if (items[i].quality < 50)
        {
            qulityIncrement(i);
        }
    }
    else
    {
        if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            items[i].quality = items[i].quality - items[i].quality;
        }
        else
        {
            if (items[i].quality > 0)
            {
                qualityAboveZero(i);
            }
        }
    }
}

void GildedRose::qualityAboveZero(const int &i)
{
    if (items[i].name != "Sulfuras, Hand of Ragnaros")
    {
        items[i].quality = items[i].quality - 1;
    }
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].quality > 0)
            {
                qualityAboveZero(i);
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                qulityIncrement(i);

                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].sellIn < 11)
                    {
                        qulityIncrement(i);
                    }

                    if (items[i].sellIn < 6)
                    {
                        qulityIncrement(i);
                    }
                }
            }
        }

        if (items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            negativeSellIn(i);
        }
    }
}
