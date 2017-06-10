/*
 * sentence.c
 *
 * */

#include <string.h>
#include "sentence.h"

int voice_sentence_set_data(Sentence* sentence, const char* data)
{
    if (data != NULL) {
        strncpy(sentence->data, data, sizeof(sentence->data) - 1);
        sentence->length = strlen(sentence->data);
        return STATUS_SUCCESS;
    }

    return STATUS_FAILED;
}

int voice_sentence_set_offset(Sentence* sentence, unsigned int offset)
{
    if ((sentence->pos + offset) >= sentence->length) {
        voice_log_error("The offset %d is too big for senten length %d position %d\n",
                                offset, sentence->length, sentence->pos);
        return STATUS_FAILED;
    }

    /* add offset into current position */
    sentence->pos += offset;

    return STATUS_SUCCESS;
}

const char* voice_sentence_get_data(Sentence* sentence)
{
    if (sentence->pos < sentence->length
        && sentence->data != NULL) {
        return &(sentence->data[sentence->pos]);
    }
    return NULL;
}

int voice_sentence_init(Sentence* sentence)
{
    if (sentence == NULL) {
        return STATUS_FAILED;
    }

    memset(sentence, 0, sizeof(Sentence));

    return STATUS_SUCCESS;
}

/* --- END --- */
