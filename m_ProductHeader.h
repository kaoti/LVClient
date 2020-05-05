#pragma once
#include <iostream>
class m_Product {
public:
	std::string m_PID;
	std::string m_Price;
	std::string m_Name;
	std::string m_ProductN;
	std::string m_Color;
	std::string m_SpainLink;
	std::string m_EnglandLink;
	std::string m_FranceLink;
	std::string m_GermanyLink;
	std::string m_ItalyLink;
	std::string m_BelgiumLink;
	std::string m_StockxLinkLink;
	std::string m_PictureLink;


	m_Product(std::string PID = "",
		std::string Price  = "",	
		std::string Name = "", 
		std::string ProductN = "",	
		std::string Color = "",
		std::string SpainLink = "",
		std::string EnglandLink = "", 
		std::string FranceLink = "",
		std::string GermanyLink = "", 
		std::string ItalyLink = "",
		std::string BelgiumLink = "", 
		std::string StockxLinkLink = "",
		std::string PictureLink = "") {

		m_PID = PID;
		m_Price = Price;
		m_Name = Name;
		m_ProductN = ProductN;
		m_Color = Color;
		m_SpainLink = SpainLink;
		m_EnglandLink = EnglandLink;
		m_FranceLink = FranceLink;
		m_GermanyLink = GermanyLink;
		m_ItalyLink = ItalyLink;
		m_BelgiumLink = BelgiumLink;
		m_StockxLinkLink = StockxLinkLink;
		m_PictureLink = PictureLink;
	}
	/*template<typename Writer>
	void m_Serialize(Writer& m_Writer) const {
		m_Writer.String("m_PID"); 
		m_Writer.String(m_PID);
		m_Writer.String("m_Price"); 
		m_Writer.String(m_Price);
		m_Writer.String("m_Name"); 
		m_Writer.String(m_Name);
		m_Writer.String("m_ProductN");
		m_Writer.String(m_ProductN);
		m_Writer.String("m_Color"); 
		m_Writer.String(m_Color);
		m_Writer.String("m_SpainLink"); 
		m_Writer.String(m_SpainLink);
		m_Writer.String("m_EnglandLink"); 
		m_Writer.String(m_EnglandLink);
		m_Writer.String("m_FranceLink"); 
		m_Writer.String(m_FranceLink);
		m_Writer.String("m_GermanyLink"); 
		m_Writer.String(m_GermanyLink);
		m_Writer.String("m_ItalyLink"); 
		m_Writer.String(m_ItalyLink);
		m_Writer.String("m_BelgiumLink");
		m_Writer.String(m_BelgiumLink);
		m_Writer.String("m_StockxLinkLink"); 
		m_Writer.String(m_StockxLinkLink);
		m_Writer.String("m_PictureLink"); 
		m_Writer.String(m_PictureLink);
	}*/
};