#ifndef SASS_TYPES_BOOLEAN_H
#define SASS_TYPES_BOOLEAN_H

#include <nan.h>
#include "value.h"
#include "sass_value_wrapper.h"

namespace SassTypes
{
  class Boolean : public SassTypes::Value {
    public:
      static Boolean& get_singleton(bool);
      static v8::Local<v8::Function> get_constructor();

      Sass_Value* get_sass_value();
      v8::Local<v8::Object> get_js_object();

      static NAN_METHOD(New);
      static NAN_METHOD(GetValue);

    private:
      Boolean(bool);

      bool value;
      Nan::Persistent<v8::Object> js_object;

      static Nan::Persistent<v8::Function> constructor;
      static bool constructor_locked;
  };
}

#endif
