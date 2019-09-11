//
// Created by emanuele on 10/09/19.
//

#include "AchievObserver.h"


AchievObserver::AchievObserver(Player *p, shared_ptr<sf::RenderWindow> rw,
                               const std::string &text, const string &filename) : subject(p),
                                                                                  texture(make_shared<sf::Texture>(
                                                                                          sf::Texture{})),
                                                                                  doneAchieve(false) {
    texture->loadFromFile(filename);
    this->text.setString(text);
    attach();
    this->text.setPosition(rw->getView().getCenter().x - this->text.getLocalBounds().width / 2.0f,
                           rw->getView().getSize().y - 40.0f);
    setPosition(this->text.getPosition().x - 10, this->text.getPosition().y);
    attach();
}

void AchievObserver::attach() {
    subject->subscribe(this);
}

void AchievObserver::detach() {
    subject->unsubscribe(this);
}

void AchievObserver::render(sf::RenderWindow *rw) {
    this->text.setPosition(subject->getPosition());
    setPosition(this->text.getPosition().x - 10, this->text.getPosition().y);
    if (doneAchieve) {
        rw->draw(*this);
        //  rw->draw(text);
    }
}
