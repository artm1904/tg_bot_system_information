#pragma once

#include <functional>
#include <nlohmann/json.hpp>
#include <string>

using FunctionAnswer = std::function<std::string()>;

class TelegramBot {
   public:
    /**
     * @brief Constract new class with usege of tg API
     * @param token tg BOT token
     * @param m_funcAnswer function to use after get new message in bot
     */
    TelegramBot(const std::string& token, const FunctionAnswer& m_funcAnswer);
    ~TelegramBot();

    /**
     * @brief Start the bot
     */
    void start();

   private:
    /**
     * @brief Process new messages
     * @param updates JSON with list of updates
     */
    void handleUpdates(const nlohmann::json& updates);

    /**
     * @brief Send message in the chosed chat
     * @param chatId the chat identificator
     * @param text the text of the message
     */
    void sendMessage(const std::string& chatId, const std::string& text);

    /**
     * @brief HTTP request to tg API
     * @param method method in tg API
     * @param payload JSON with request parameters
     */
    nlohmann::json makeRequest(const std::string& method, const nlohmann::json& payload = {});

    /**
     * @brief contains tg API adress and token
     */
    std::string m_apiUrl;

    /**
     * @brief contains bot's token
     */
    std::string m_botToken;

    /**
     * @brief contains the last process update from tg API
     */
    std::string m_lastUpdateId;

    /**
     * @brief unction to use after get new message in bot
     */
    FunctionAnswer m_funcAnswer;
};