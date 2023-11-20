#include <GildedRose.h>


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::increaseItemAtIndexByOne(int sellInOfItem) 
{
    if (items[i].sellIn < sellInOfItem && items[i].quality < fifty)
        items[i].quality++;
}
void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != AB && items[i].name != BPTATC)
            if (items[i].name != SHOR && items[i].quality > 0)
                items[i].quality--;
                
        else if (items[i].quality < fifty)
        {
            items[i].quality++;
            if (items[i].name == BPTATC)
            {
                increaseItemAtIndexByOne(11);
                increaseItemAtIndexByOne(6);
            }
        }
        if (items[i].name != SHOR)
            items[i].sellIn--;
            
        if (items[i].sellIn < 0)
        {
            if (items[i].name != AB)
            {
                if (items[i].name != BPTATC)
                    if (items[i].name != SHOR && items[i].quality > 0)
                        items[i].quality--;
                else
                    items[i].quality = 0;
            }
            else if (items[i].quality < fifty)
                items[i].quality++;
        }
    }
}

