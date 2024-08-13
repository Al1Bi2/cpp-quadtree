#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
template<typename T, std::size_t TDim>
class NVector {
	std::shared_ptr<spdlog::logger> log;
public:
	std::vector<T> coords;

	NVector() : coords(TDim) {
		std::shared_ptr<spdlog::logger> log = spdlog::get("multi_sink");
		if (! log) {
			std::vector<spdlog::sink_ptr> sinks;
			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			console_sink->set_level(spdlog::level::debug);
			console_sink->set_pattern("[log] [%^%l%$] %v");
			sinks.push_back(console_sink);
			auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true);
			file_sink->set_level(spdlog::level::info);
			sinks.push_back(file_sink);
			log = std::make_shared<spdlog::logger>("multi_sink", begin(sinks),end(sinks));
			spdlog::register_logger(log);
			spdlog::set_default_logger(log);
			spdlog::set_level(spdlog::level::debug);
			spdlog::warn("this should appear in both console and file");
			spdlog::info("this message should not appear in the console, only in the file");
		/*
			log = std::make_shared<spdlog::logger>("log", std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt"));
			spdlog::register_logger(log);
			spdlog::set_default_logger(log);
			log.set_level(spdlog::level:debug);
			*/
		}
	}
	NVector<T, TDim>& operator+=(NVector<T, TDim> rhs) {
		spdlog::debug("two vectors with {0} dimensions added", TDim);
		for (int i = 0; i < TDim; i++) {
			coords[i] += rhs.coords[i];
		}

		return *this;
	}

	NVector<T, TDim>& operator-=(NVector<T, TDim> rhs) {
		spdlog::debug("two vectors with {0} dimensions added", TDim);
		for (int i = 0; i < TDim; i++) {
			coords[i] -= rhs.coords[i];
		}

		return *this;
	}

	NVector<T, TDim>& operator*=(T rhs) {
		spdlog::debug("vector with {0} dimensions added multiplied by {1}", TDim, rhs);
		for (int i = 0; i < TDim; i++) {
			coords[i] *= rhs;
		}
		return *this;
	}

	NVector<T, TDim>& operator/=(T rhs) {
		spdlog::debug("vector with {0} dimensions added multiplied by {1}", TDim, rhs);
		for (int i = 0; i < TDim; i++) {
			coords[i] /= rhs;
		}
		return *this;
	}

	std::string print() {
		std::string result = "Vector" + std::to_string(TDim) + "(";
		for (int i = 0; i < TDim; i++) {
			result += std::to_string(coords[i]) + ", ";

		}
		result += ")\n";
		return result;
	}
};
