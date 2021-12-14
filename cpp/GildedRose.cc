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

		auto decraseItemQuality = [](Item& item) { if (item.quality > 0) item.quality--; };

		if (item.name == "Sulfuras, Hand of Ragnaros")
		{
			continue;
		}

		if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert")
		{
			decraseItemQuality(item);
		}
		else if (item.quality < 50)
		{
			item.quality++;

			if (item.name == "Backstage passes to a TAFKAL80ETC concert")
			{
				if (item.sellIn && item.quality < 50)
				{
					if (item.sellIn < 6)
					{
						item.quality++;
					}

					if (item.sellIn < 11)
					{
						item.quality++;
					}
				}
			}
		}

		item.sellIn--;



		if (item.sellIn < 0)
		{
			if (item.name != "Aged Brie")
			{
				decraseItemQuality(item);
			}
			else if (item.quality < 50)
			{
				item.quality++;
			}

			if (item.name == "Backstage passes to a TAFKAL80ETC concert")
			{
				item.quality = 0;
			}
		}
	}
}