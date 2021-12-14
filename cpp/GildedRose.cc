#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item>&& items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
	for (int i = 0; i < items.size(); i++)
	{
		Item& item = items[i];
		if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert")
		{
			if (item.quality > 0 && item.name != "Sulfuras, Hand of Ragnaros")
			{
				item.quality--;
			}
		}
		else if (item.quality < 50)
		{
			item.quality++;

			if (item.name == "Backstage passes to a TAFKAL80ETC concert")
			{
				if (item.sellIn < 11 && item.quality < 50)
				{
					item.quality++;
				}

				if (item.sellIn < 6 && item.quality < 50)
				{
					item.quality++;
				}
			}
		}

		if (item.name != "Sulfuras, Hand of Ragnaros")
		{
			item.sellIn = item.sellIn - 1;
		}

		if (item.sellIn < 0)
		{
			if (item.name != "Aged Brie")
			{
				if (item.name != "Backstage passes to a TAFKAL80ETC concert")
				{
					if (item.quality > 0)
					{
						if (item.name != "Sulfuras, Hand of Ragnaros")
						{
							item.quality = item.quality - 1;
						}
					}
				}
				else
				{
					item.quality = item.quality - item.quality;
				}
			}
			else
			{
				if (item.quality < 50)
				{
					item.quality = item.quality + 1;
				}
			}
		}
	}
}
