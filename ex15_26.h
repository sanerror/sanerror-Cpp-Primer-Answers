#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price);
	Quote(const Quote&);
	Quote(Quote&&)noexcept;
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&) noexcept;
	virtual ~Quote();

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const;
	virtual void debug() const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string&, double,
		std::size_t, double);
	Disc_quote(const Disc_quote&);
	Disc_quote(Disc_quote&&)noexcept;
	Disc_quote& operator=(const Disc_quote&);
	Disc_quote& operator=(Disc_quote&&) noexcept;
	virtual ~Disc_quote() override;

	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0;
};


class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double,
		std::size_t, double);
	Bulk_quote(const Bulk_quote&);
	Bulk_quote(Bulk_quote&&)noexcept;
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&);
	virtual ~Bulk_quote() override;

	double net_price(std::size_t) const override;
};