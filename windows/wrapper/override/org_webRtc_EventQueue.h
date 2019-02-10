
#ifndef WRAPPER_USE_GENERATED_ORG_WEBRTC_EVENTQUEUE

#pragma once

#include <wrapper/generated/types.h>

namespace wrapper {
  namespace org {
    namespace webRtc {

      struct EventQueue
      {
        static EventQueuePtr wrapper_create() noexcept;
        virtual ~EventQueue() noexcept {}


        virtual void wrapper_init_org_webRtc_EventQueue(AnyPtr queue) noexcept { ZS_MAYBE_USED(queue); }
        static wrapper::org::webRtc::EventQueuePtr getOrCreateThreadQueueByName(String queueName) noexcept;
        static wrapper::org::webRtc::EventQueuePtr createThreadQueuePool(
          String queueName,
          uint64_t minimumNumberOfThreads
        ) noexcept;
        static wrapper::org::webRtc::EventQueuePtr getDefaultForUi() noexcept;

        virtual AnyPtr get_queue() noexcept = 0;
      };

    } // webRtc
  } // org
} // namespace wrapper

#endif //ifndef WRAPPER_USE_GENERATED_ORG_WEBRTC_EVENTQUEUE
