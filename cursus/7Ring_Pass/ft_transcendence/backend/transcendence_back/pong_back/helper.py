from django.core.mail import send_mail
from django.conf import settings
from django.http import HttpResponseServerError
from django.core.exceptions import ValidationError
import redis
import random
import math
import logging

logger = logging.getLogger(__name__)

def getPin():
    random_number = random.randint(100000, 999999)
    logger.info("Generated PIN: %s", random_number)
    return str(random_number)

def send_otp_email(email, user_id):
    otp = get_otp(user_id)
    if not otp:
        logger.error("No valid OTP found for user ID: %s", user_id)
        raise ValidationError("No valid OTP found")
    subject = 'Your OTP Code for Verification'
    message = f'Please use the following OTP code to complete your registration: {otp}. This code is valid for 5 minutes.'
    email_from = settings.EMAIL_HOST_USER
    recipient_list = [email]
    logger.info("Sent OTP email to: %s", email)
    send_mail(subject, message, email_from, recipient_list)

def save_otp(user_id, otp):
    try:
        redis_instance = redis.StrictRedis(host=settings.REDIS_HOST,
                                  port=settings.REDIS_PORT, db=1)
        redis_instance.setex(f":1:user:otp:{user_id}", 300, otp)
        logger.info("Saved OTP for user ID: %s", user_id)
        return True
    except redis.RedisError as e:
        logger.error("Error saving OTP in Redis for user ID: %s, error: %s", user_id, e)
        raise HttpResponseServerError(f"Error saving OTP in Redis: {e}")

def get_otp(user_id):
    try:
        redis_instance = redis.StrictRedis(host=settings.REDIS_HOST,
                                  port=settings.REDIS_PORT, db=1)
        otp = redis_instance.get(f":1:user:otp:{user_id}")
        if otp:
            logger.info("Retrieved OTP for user ID: %s", user_id)
            return otp.decode('utf-8')
        logger.warning("No OTP found for user ID: %s", user_id)
        return None
    except redis.RedisError as e:
        logger.error("Error getting OTP from Redis for user ID: %s, error: %s", user_id, e)
        raise HttpResponseServerError(f"Error getting OTP from Redis: {e}")

def clear_user_cache(user_id):
    try:
        redis_instance = redis.StrictRedis(host=settings.REDIS_HOST,
                                           port=settings.REDIS_PORT, db=1)
        patterns = [f":1:user_data_{user_id}", f":1:user:otp:{user_id}"]
        for pattern in patterns:
            cursor = '0'
            while cursor != 0:
                cursor, keys_to_delete = redis_instance.scan(cursor=cursor, match=pattern + "*", count=100)
                for key in keys_to_delete:
                    redis_instance.delete(key)
        logger.info(f"Clearing cache for user {user_id}")
        return True
    except redis.RedisError as e:
        logger.error(f"Error clearing cache for user {user_id}: {e}")
        return False