#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Создание базового класса 
class Widget {
public:
	virtual ~Widget() = default;

	// Устaновка род.виджета
	void setParent(std::shared_ptr<Widget> parent) {
		parent_ = std::move(parent);
	}

	//Указатель на род.виджет
	std::shared_ptr<Widget> getParent() const {
		return parent_;
	}
		// Виртуальная функция для определения типа виджета
	virtual std::string getType() const {
		return "Widget";
	}
	// Добавление дочернего виджета
	virtual void addChild(std::shared_ptr<Widget> child) {
		children_.push_back(std::move(child));
	}
protected:
	std::shared_ptr <Widget> parent_; // Указатель на родительский виджет
	std::vector<std::shared_ptr<Widget>> children_; // Вектор дочерних виджетов

};

//класс TabWidget
class TabWidget : public Widget{
public:
	
	// Переопределение метода getType()
	std::string getType() const override {
		return "TabWidget";
	}
	
};

//класс CalendarWidget
class CalendarWidget : public Widget {
public:
	// Переопределение метода getType()
	std::string getType() const override {
		return "CalendarWidget";
	}
};

int main() {
	// Пример использования иерархии классов
	auto tabWidget = std::make_shared<TabWidget>(); // Создание объекта типа TabWidget
	auto calendarWidget = std::make_shared<CalendarWidget>(); // Создание объекта типа CalendarWidget

	tabWidget->addChild(calendarWidget); // Добавление CalendarWidget в качестве дочернего для TabWidget
	calendarWidget->setParent(tabWidget); // Установка TabWidget в качестве родительского для CalendarWidget

	// Вывод типов виджетов
	std::cout << "Type of tabWidget: " << tabWidget->getType() << std::endl;
	std::cout << "Type of calendarWidget: " << calendarWidget->getType() << std::endl;

	return 0;
}
