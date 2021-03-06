
#include "impl_org_webRtc_RTCVideoReceiverStats.h"
#include "impl_org_webRtc_RTCVideoHandlerStats.h"
#include "impl_org_webRtc_RTCMediaHandlerStats.h"
#include "impl_org_webRtc_RTCStats.h"

#include "impl_org_webRtc_enums.h"
#include "Org.WebRtc.Glue.events.h"

using ::zsLib::Milliseconds;
using ::zsLib::String;
using ::zsLib::Optional;
using ::zsLib::Any;
using ::zsLib::AnyPtr;
using ::zsLib::AnyHolder;
using ::zsLib::Promise;
using ::zsLib::PromisePtr;
using ::zsLib::PromiseWithHolder;
using ::zsLib::PromiseWithHolderPtr;
using ::zsLib::eventing::SecureByteBlock;
using ::zsLib::eventing::SecureByteBlockPtr;
using ::std::shared_ptr;
using ::std::weak_ptr;
using ::std::make_shared;
using ::std::list;
using ::std::set;
using ::std::map;

// borrow definitions from class
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCVideoReceiverStats::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::WrapperType, WrapperType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::NativeType, NativeType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::NativeStats, NativeStats);

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCStats, ImplRTCStats);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCMediaHandlerStats, ImplRTCMediaHandlerStats);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCVideoHandlerStats, ImplRTCVideoHandlerStats);

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::IEnum, UseEnum);

namespace wrapper { namespace impl { namespace org { namespace webRtc { ZS_DECLARE_SUBSYSTEM(wrapper_org_webRtc); } } } }

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::RTCVideoReceiverStats::RTCVideoReceiverStats() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::RTCVideoReceiverStatsPtr wrapper::org::webRtc::RTCVideoReceiverStats::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::webRtc::RTCVideoReceiverStats>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::RTCVideoReceiverStats::~RTCVideoReceiverStats() noexcept
{
  thisWeak_.reset();
}

//------------------------------------------------------------------------------
void wrapper::impl::org::webRtc::RTCVideoReceiverStats::trace() noexcept
{
  if (!ZS_EVENTING_IS_LOGGING(Detail))
    return;

  auto type = get_statsType();

  ZS_EVENTING_21(
    x, i, Detail, RTCVideoReceiverStats, stats, Stats, Info,
    string, type, type.has_value() ? UseEnum::toString(type.value()) : "",
    string, otherType, get_statsTypeOther(),
    string, id, get_id(),
    string, trackIdentifier, get_trackIdentifier(),
    bool, hasRemoteSourceValue, get_remoteSource().has_value(),
    bool, remoteSource, get_remoteSource().has_value() ? get_remoteSource().value() : false,
    bool, ended, get_ended(),
    string, kind, get_kind(),
    string, priority, UseEnum::toString(get_priority()),
    ulong, frameWidth, get_frameWidth(),
    ulong, frameHeight, get_frameHeight(),
    double, framesPerSecond, get_framesPerSecond(),
    duration, estimatedPlayoutTimestamp, zsLib::timeSinceEpoch<Milliseconds>(get_estimatedPlayoutTimestamp()).count(),
    duration, jitterBufferDelay, get_jitterBufferDelay().count(),
    ulonglong, jitterBufferEmittedCount, get_jitterBufferEmittedCount(),
    ulong, framesReceived, get_framesReceived(),
    ulong, keyFramesReceived, get_keyFramesReceived(),
    ulong, framesDecoded, get_framesDecoded(),
    ulong, framesDropped, get_framesDropped(),
    ulong, partialFramesLost, get_partialFramesLost(),
    ulong, fullFramesLost, get_fullFramesLost()
  );

}

//------------------------------------------------------------------------------
::zsLib::Time wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_timestamp() noexcept
{
  return ImplRTCStats::get_timestamp(native_.get());
}

//------------------------------------------------------------------------------
Optional< wrapper::org::webRtc::RTCStatsType > wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_statsType() noexcept
{
  return ImplRTCStats::get_statsType(native_.get());
}

//------------------------------------------------------------------------------
String wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_statsTypeOther() noexcept
{
  return ImplRTCStats::get_statsTypeOther(native_.get());
}

//------------------------------------------------------------------------------
String wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_id() noexcept
{
  return ImplRTCStats::get_id(native_.get());
}

//------------------------------------------------------------------------------
String wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_trackIdentifier() noexcept
{
  return ImplRTCMediaHandlerStats::get_trackIdentifier(&cast());
}

//------------------------------------------------------------------------------
Optional< bool > wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_remoteSource() noexcept
{
  return ImplRTCMediaHandlerStats::get_remoteSource(&cast());
}

//------------------------------------------------------------------------------
bool wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_ended() noexcept
{
  return ImplRTCMediaHandlerStats::get_ended(&cast());
}

//------------------------------------------------------------------------------
String wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_kind() noexcept
{
  return ImplRTCMediaHandlerStats::get_kind(&cast());
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::RTCPriorityType wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_priority() noexcept
{
  return ImplRTCMediaHandlerStats::get_priority(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_frameWidth() noexcept
{
  return ImplRTCVideoHandlerStats::get_frameWidth(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_frameHeight() noexcept
{
  return ImplRTCVideoHandlerStats::get_frameHeight(&cast());
}

//------------------------------------------------------------------------------
double wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_framesPerSecond() noexcept
{
  return ImplRTCVideoHandlerStats::get_framesPerSecond(&cast());
}

//------------------------------------------------------------------------------
::zsLib::Time wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_estimatedPlayoutTimestamp() noexcept
{
  return get_estimatedPlayoutTimestamp(&cast());
}

//------------------------------------------------------------------------------
::zsLib::Milliseconds wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_jitterBufferDelay() noexcept
{
  return get_jitterBufferDelay(&cast());
}

//------------------------------------------------------------------------------
unsigned long long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_jitterBufferEmittedCount() noexcept
{
  return get_jitterBufferEmittedCount(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_framesReceived() noexcept
{
  return get_framesReceived(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_keyFramesReceived() noexcept
{
  return get_keyFramesReceived(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_framesDecoded() noexcept
{
  return get_framesDecoded(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_framesDropped() noexcept
{
  return get_framesDropped(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_partialFramesLost() noexcept
{
  return get_partialFramesLost(&cast());
}

//------------------------------------------------------------------------------
unsigned long wrapper::impl::org::webRtc::RTCVideoReceiverStats::get_fullFramesLost() noexcept
{
  return get_fullFramesLost(&cast());
}

//------------------------------------------------------------------------------
WrapperTypePtr WrapperImplType::toWrapper(NativeTypeUniPtr value) noexcept
{
  if (!value) return WrapperTypePtr();
  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  result->native_ = std::move(value);
  return result;
}

//------------------------------------------------------------------------------
::zsLib::Time WrapperImplType::get_estimatedPlayoutTimestamp(const NativeStats *) noexcept
{
  return {};
}

//------------------------------------------------------------------------------
::zsLib::Milliseconds WrapperImplType::get_jitterBufferDelay(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->jitter_buffer_delay.is_defined()) return {};
  return Milliseconds(static_cast<Milliseconds::rep>((*(native->jitter_buffer_delay))) * 1000);
}

//------------------------------------------------------------------------------
unsigned long long WrapperImplType::get_jitterBufferEmittedCount(const NativeStats *) noexcept
{
  return {};
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_framesReceived(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->frames_received.is_defined()) return {};
  return *(native->frames_received);
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_keyFramesReceived(const NativeStats *) noexcept
{
  return {};
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_framesDecoded(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->frames_decoded.is_defined()) return {};
  return *(native->frames_decoded);
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_framesDropped(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->frames_dropped.is_defined()) return {};
  return *(native->frames_dropped);
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_partialFramesLost(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->partial_frames_lost.is_defined()) return {};
  return *(native->partial_frames_lost);
}

//------------------------------------------------------------------------------
unsigned long WrapperImplType::get_fullFramesLost(const NativeStats *native) noexcept
{
  ZS_ASSERT(native);
  if (!native) return {};

  if (!native->full_frames_lost.is_defined()) return {};
  return *(native->full_frames_lost);
}

//------------------------------------------------------------------------------
const NativeStats &WrapperImplType::cast() noexcept
{
  ZS_ASSERT(native_);
  return native_->cast_to<NativeStats>();
}
