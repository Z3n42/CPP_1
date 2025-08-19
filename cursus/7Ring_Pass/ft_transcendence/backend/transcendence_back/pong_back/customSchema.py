
from rest_framework.schemas import AutoSchema
from rest_framework.compat import coreapi, coreschema

class CustomAutoSchema(AutoSchema):
    def get_manual_fields(self, path, method):
        extra_fields = []
        if method.lower() == 'put':
            extra_fields = [
                coreapi.Field(
                    "email",
                    required=False,
                    location="form",
                    schema=coreschema.String(),
                    description="User's email address."
                ),
                coreapi.Field(
                    "username",
                    required=False,
                    location="form",
                    schema=coreschema.String(),
                    description="User's username."
                ),
                coreapi.Field(
                    "password",
                    required=False,
                    location="form",
                    schema=coreschema.String(),
                    description="User's new password."
                ),
                coreapi.Field(
                    "wins",
                    required=False,
                    location="form",
                    schema=coreschema.Integer(),
                    description="Total number of user's wins."
                ),
                coreapi.Field(
                    "games",
                    required=False,
                    location="form",
                    schema=coreschema.Integer(),
                    description="Total number of user's games."
                ),
                coreapi.Field(
                    "is_active",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user is active."
                ),
                coreapi.Field(
                    "is_online",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user is online."
                ),
                coreapi.Field(
                    "is_staff",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user is a staff member."
                ),
                coreapi.Field(
                    "is_superuser",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user is a superuser."
                ),
                coreapi.Field(
                    "is_ft",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user is an Ft user."
                ),
                coreapi.Field(
                    "avatar",
                    required=False,
                    location="form",
                    schema=coreschema.String(),
                    description="User's avatar."
                ),
                coreapi.Field(
                    "friends",
                    required=False,
                    location="form",
                    schema=coreschema.Array(),
                    description="List of user's friends."
                ),
                coreapi.Field(
                    "is_2fa",
                    required=False,
                    location="form",
                    schema=coreschema.Boolean(),
                    description="Indicates whether the user has 2fa."
                ),
            ]
        manual_fields = super().get_manual_fields(path, method)
        return manual_fields + extra_fields
