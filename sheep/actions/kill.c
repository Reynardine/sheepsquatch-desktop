#include "sheep/actions.h"
#include "sheep/client.h"

static gboolean run_func(ObActionsData *data, gpointer options);

void action_kill_startup(void)
{
    actions_register("Kill",
                     NULL, NULL,
                     run_func);
}

/* Always return FALSE because its not interactive */
static gboolean run_func(ObActionsData *data, gpointer options)
{
    if (data->client)
        client_kill(data->client);

    return FALSE;
}
