#pragma once
#include <SFML\Graphics.hpp>

int languageInfoNow = 0;

sf::String languageInfoEnglish[24] = {
	"Tutorial",
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
	"Meele\nTake half damage from Ranged squads.",
	"Range\nIgnore enemy damage when the attack.\nCan't damage enemy when was attacked.",
	"Cavalry\nCan attack twice each turn.",
	"Anti-Cavalry\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.",
	"Anti-Cavalry Cavalry\nCan attack twice each turn.\nDeal double damage to Cavalry squads.\nIf a Cavalry squad attacks an Anti-Cavalry\nwith its first hit of a turn, it loses the ability\nto attack a second time that turn.",
	"Doesn't have uniqe ability.",
	""
};

sf::String languageInfoRussian[24] = {
	L"Обучение",
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
	L"Ближний бой\nПолучает половину урона от войск Дальнего боя.",
	L"Дальний бой\nИгнорирует урон противника когда атакует.\nНе наносит урон в ответ когда был атакован.",
	L"Кавалерия\nМожет атаковать дважды за один ход.",
	L"Анти-Кавалерия\nНаносит двойной урон войскам Кавалерии\nпротивника. Если Кавалерийский отряд атаковал\nАнти-кавалерийский на своём первом ударе за ход,\nто он теряет возможность атаковать второй раз\nза этот ход.",
	L"Анти-Кавалерийская Кавалерия\nМожет атаковать дважды за один ход.\nНаносит двойной урон войскам Кавалерии\nпротивника. Если Кавалерийский отряд атаковал\nАнти-кавалерийский на своём первом ударе за ход,\nто он теряет возможность атаковать второй раз\nза этот ход.",
	L"Нет уникальных особенностей.",
	L""
};

sf::String languageInfoUkrainian[24] = {
	L"Навчання",
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
	L"Ближній бій\nОтримує половину шкоди від військ\nДальнього бою.",
	L"Дальній бій\nІгнорує шкоду супротивника коли атакує.\nНе наносить шкоди у відповідь\nколи був атакований.",
	L"Кавалерія\nМоже атакувати двічі за один хід.",
	L"Анти-Кавалерія\nНаносить подвійну шкоду військам Кавалерії\nсупротивника. Якщо Кавалерійский загін атакував\nАнти-кавалерійский на своїй першій атаці за хід,\nто він втрачає можливістьатакувати другий раз\nза цей хід.",
	L"Анти-Кавалерійска Кавалерія\nМоже атакувати двічі за один хід.\nНаносить подвійну шкоду військам Кавалерії\nсупротивника. Якщо Кавалерійский загін атакував\nАнти-кавалерійский на своїй першій атаці за хід,\nто він втрачає можливістьатакувати другий раз\nза цей хід.",
	L"Немає унікальних здібностей.",
	L""
};

sf::String languageInfoString(int indexOfString)
{
	switch (languageInfoNow)
	{
	case 0:
		return languageInfoEnglish[indexOfString];
		break;
	case 1:
		return languageInfoRussian[indexOfString];
		break;
	case 2:
		return languageInfoUkrainian[indexOfString];
		break;
	default:
		return "";
		break;
	}
}