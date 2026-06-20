import { describe, expect, it } from "vitest";
import app from "../src/app.js";

describe("API test", () => {
  it("Status Check", async () => {
    const response = await app.inject({
      method: "GET",
      url: "/",
    });

    expect(response.statusCode).toBe(200);
    expect(response.json()).toEqual({ message: "OK" });
  });

  it("POST / - Should pass", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: "hello" },
    });

    expect(response.statusCode).toBe(201);
    expect(response.json()).toEqual({ title: "hello" });
  });

  it("POST / - Should fail because title is number", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: 1 },
    });

    expect(response.statusCode).toBe(400);
    const data = response.json();
    expect(data.code).toBe("FST_ERR_VALIDATION");
    expect(data.message).toBe("body/title must be string");
  });

  it("POST / - Should fail because title is empty", async () => {
    const response = await app.inject({
      method: "POST",
      url: "/",
      payload: { title: "" },
    });

    expect(response.statusCode).toBe(400);
    const data = response.json();
    expect(data.code).toBe("FST_ERR_VALIDATION");
    expect(data.message).toBe(
      "body/title must NOT have fewer than 1 characters",
    );
  });
});
