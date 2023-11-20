#include <GildedRose.h>

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::increaseItemByOneIfSellInLessThan(int sellInOfItem, Item& item) 
{
    if (item.sellIn < sellInOfItem && item.quality < fifty)
        item.quality++;
}

void GildedRose::updateQuality()
{
     
    for (Item& item: items)
    {
        if (item.name != AB && item.name != BPTATC)
            if (item.name != SHOR && item.quality > 0)
                item.quality--;
                
        else if (item.quality < fifty)
        {
            item.quality++;
            if (item.name == BPTATC)
            {
                increaseItemByOneIfSellInLessThan(11, item);
                increaseItemByOneIfSellInLessThan(6, item);
            }
        }
        if (item.name != SHOR)
            item.sellIn--;
            
        if (item.sellIn < 0)
        {
            if (item.name != AB)
            {
                if (item.name != BPTATC)
                    if (item.name != SHOR && item.quality > 0)
                        item.quality--;
                else
                    item.quality = 0;
            }
            else if (item.quality < fifty)
                item.quality++;
        }
    }
}
