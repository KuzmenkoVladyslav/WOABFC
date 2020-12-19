#pragma once
#include <SFML\Graphics.hpp>

static int state;

static int getState()
{
	return state;
}

static void setState(int newState)
{
	state = newState;
}

static sf::String languageEnglish[26] = {
	"HotSeat",
	"Multiplayer",
	"Settings",
	"How to play",
	"Exit",
	"Era: ",
	"Name: ",
	"Type: ",
	"Ancient",
	"Classic",
	"Medival",
	"Renaissancee",
	"Industrial",
	"Modern",
	"Atomic",
	"Information",
	"Future",
	"Meele\nTake half damage from Ranged\nsquads.",
	"Range\nIgnore enemy damage when\nthe attack. Can't damage\nenemy when was attacked.",
	"Cavalry\nCan attack infinite times.",
	"Anti-Cavalry\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalry it loses\nthe ability to attack a second\ntime that turn.",
	"Anti-Cavalry Cavalry\nCan attack infinite times.\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalry it loses\nthe ability to attack a second\ntime that turn.",
	"Doesn't have uniqe ability.",
	"Cost: ",
	" points of the turn.",
	"You are running out of space or points for the turn."
};

static sf::String languageRussian[26] = {
	L"HotSeat",
	L"Многопользовательская игра",
	L"Настройки",
	L"Как играть",
	L"Выход",
	L"Эпоха: ",
	L"Название: ",
	L"Тип: ",
	L"Древний мир",
	L"Классическая эра",
	L"Средневековье",
	L"Эпоха Возрождения",
	L"Индустриальная эра",
	L"Новое время",
	L"Эпоха атома",
	L"Информационная эра",
	L"Будущее",
	L"Ближний бой\nПолучает половину урона от\nвойск Дальнего боя.",
	L"Дальний бой\nИгнорирует урон противника\nкогда атакует.\nНе наносит урон в ответ\nкогда был атакован.",
	L"Кавалерия\nМожет атаковать пока не умрёт.",
	L"Анти-Кавалерия\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский,\nто он теряет возможность\nатаковать в этот ход.",
	L"Анти-Кавалерийская Кавалерия\nМожет атаковать пока не умрёт.\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский,\nто он теряет возможность\nатаковать в этот ход.",
	L"Нет уникальных\nособенностей.",
	L"Стоимость: ",
	L" баллов действий.",
	L"У Вас не хватает места или баллов действий!"
};

static sf::String languageUkrainian[26] = {
	L"HotSeat",
	L"Багато користувальницька гра",
	L"Налаштування",
	L"Як грати",
	L"Вийти",
	L"Епоха: ",
	L"Назва: ",
	L"Тип: ",
	L"Стародавній світ",
	L"Класична ера",
	L"Середньовіччя",
	L"Епоха Відродження",
	L"Індустріальна ера",
	L"Новий час",
	L"Епоха атому",
	L"Інформаційна ера",
	L"Майбутнє",
	L"Ближній бій\nОтримує половину шкоди від\nвійськ Дальнього бою.",
	L"Дальній бій\nІгнорує шкоду супротивника\nколи атакує. Не наносить шкоди\nу відповідь коли був атакований.",
	L"Кавалерія\nМоже атакувати доки не помре.",
	L"Анти-Кавалерия\nНаносить подвійну шкоду війскам\nКавалерії супротивника. Якщо\nКавалерійский загін атакував\nАнти-кавалерійский, то він втрачає\nможливість атакувати у цей хід.",
	L"Анти-Кавалерийская Кавалерия\nМоже атакувати доки не помре.\nНаносить подвійну шкоду війскам\nКавалерії супротивника. Якщо\nКавалерійский загін атакував\nАнти-кавалерійский, то він втрачає\nможливість атакувати у цей хід.",
	L"Немає унікальних здібностей.",
	L"Вартість: ",
	L" балів дій.",
	L"У Вас недостатньо місця або балів дій!"
};

static sf::String languageString(int indexOfString)
{
	switch (state)
	{
	case 0:
		return languageEnglish[indexOfString];
		break;
	case 1:
		return languageRussian[indexOfString];
		break;
	case 2:
		return languageUkrainian[indexOfString];
		break;
	default:
		return "";
		break;
	}
}