﻿#pragma once

#include <QPixmap>
#include <QImage>
#include <QBitmap>
#include <QPainter>
#include <QStringList>
#include <QCryptographicHash>
#include <QDateTime>
#include <QTimer>
#include <json.hpp>
#include <fstream>
#include <httplib.h>
#include "TimeStampToken.h"

namespace thatboy
{
	namespace utils
	{
		QPixmap roundedPixmap(const QPixmap& src);

		void from_json(const nlohmann::json& j, QString& string);
		void from_json(const nlohmann::json& j, QStringList& stringList);
		void from_json(const nlohmann::json& j, QRect& rect);
		void to_json(nlohmann::json& j, const QString& string);
		void to_json(nlohmann::json& j, const QStringList& stringList);
		void to_json(nlohmann::json& j, const QRect& rect);
		
		void loadConfig();
		void saveConfig();
		void loadUsers();
		void saveUsers();

		TimeStampToken generateTrustedToken(QString password);
	}
	namespace storage
	{
		constexpr auto DefaultUserAvatarUrl{ ":/LiveLoginUnit/res/avatar.png" };
		constexpr auto DefaultMaleAvatarUrl{ ":/LiveLoginUnit/res/avatar-male.png" };
		constexpr auto DefaultFemaleAvatarUrl{ ":/LiveLoginUnit/res/avatar-female.png" };
		constexpr const char* DefaultAvatarUrlGroup[3]
		{
			DefaultUserAvatarUrl
			, DefaultMaleAvatarUrl
			, DefaultFemaleAvatarUrl
		};

		extern httplib::Client accountVerifyClient;
		constexpr auto RegexAccount{ R"(^[A-Za-z][A-Za-z0-9_-]{3,15}$)" };
		constexpr auto RegexPassword{ R"(^[A-Za-z0-9._~!@#$^&*]{6,24}$)" };
		constexpr auto ConfigFilePath{ "application.config" };
		constexpr int LoginErrorLabelTime{ 8000 };

		constexpr auto RegisterUrl{"http://jaychou.thatboy.icu"};
		constexpr auto ResetPasswordUrl{"https://thatboy.info"};

		extern nlohmann::json config;
		extern nlohmann::json users;

		extern bool pswdFromConfig;

		extern nlohmann::json currentUser;
	}
}
using thatboy::TimeStampToken;
using thatboy::utils::to_json;
using thatboy::utils::from_json;
using thatboy::to_json;
using thatboy::from_json;