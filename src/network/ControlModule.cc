#include "Router.h"

void ControlModule::someFunction() {
    Router *router = check_and_cast<Router *>(getModuleByPath("network.router[0]"));
    if (router) {
        router->setMaxBufferSize(200);
        router->setArbiterWeights(0.5);
        router->throttle(true);
    }
}
